#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

// #include "prografo.h"

extern "C" int run_prografo(char* executionType, char* filePath);

wxString executionTypes[] = { 
        "-a", 
        "-b", 
        "-c", 
        "-d"
    };
wxString executionTypesDescriptions[] = { 
        "Encontrar um maximo (paralelizado)", 
        "Encontrar um maximo (linear)", 
        "Encontrar todos os maximos", 
        "Encontrar todos os maximais" 
    };
wxString selectedFilePath = "";
wxString selectedExecutionType = executionTypes[0];


class Prografo: public wxApp 
{
    public:
        virtual bool OnInit();
};

class MainFrame: public wxFrame
{
    public:
        MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    private:
        void OnAbout(wxCommandEvent& event);
        void OnFileInputButtonClicked(wxCommandEvent& event);
        void OnExecutionTypeSelected(wxCommandEvent& event);
        void OnStartButtonClicked(wxCommandEvent& event);
        void UpdateStatus(const wxString& label, const wxColour& textColour, const wxColour& panelColour);
        wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_FileInputButton = 1,
    ID_ExecutionTypeRadioButton = 2,
    ID_StartButton = 3,
    ID_StatusPanel = 4,
    ID_StatusText = 5
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
    EVT_MENU(ID_FileInputButton, MainFrame::OnFileInputButtonClicked)
    EVT_MENU(ID_StartButton, MainFrame::OnStartButtonClicked)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(Prografo);

bool Prografo::OnInit() 
{
    MainFrame *frame = new MainFrame("Prografo - Software", wxPoint(50, 50), wxSize(440, 530));
    frame->Show(true);
    return true;
}

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    wxStaticText* titleLabel = new wxStaticText(this, wxID_ANY, "Prografo", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    titleLabel->SetFont(wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    sizer->Add(titleLabel, 0, wxALIGN_LEFT | wxALL, 10);

    wxStaticText* fileSelectLabel = new wxStaticText(this, wxID_ANY, "Selecione o grafo no formato dimacs (.col):", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    fileSelectLabel->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    sizer->Add(fileSelectLabel, 0, wxALIGN_LEFT | wxALL, 10);

    wxButton* fileInputButton = new wxButton(this, ID_FileInputButton, "Selecionar arquivo...");
    fileInputButton->Bind(wxEVT_BUTTON, &MainFrame::OnFileInputButtonClicked, this);
    fileInputButton->SetMinSize(wxSize(420, -1));
    sizer->Add(fileInputButton, 0, wxALIGN_LEFT | wxLEFT | wxRIGHT | wxBOTTOM, 10);

    wxRadioBox* radioBox = new wxRadioBox(this, ID_ExecutionTypeRadioButton,
                                          "Selecione o tipo de execucao:",
                                          wxDefaultPosition,
                                          wxDefaultSize,
                                          WXSIZEOF(executionTypes), executionTypesDescriptions, 1, wxRA_SPECIFY_COLS);

    radioBox->Bind(wxEVT_RADIOBOX, &MainFrame::OnExecutionTypeSelected, this);
    sizer->Add(radioBox, 0, wxEXPAND | wxALL, 10);

    wxStaticText* statusTitleLabel = new wxStaticText(this, wxID_ANY, "Status", wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);
    statusTitleLabel->SetFont(wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    sizer->Add(statusTitleLabel, 0, wxALIGN_LEFT | wxALL, 10);

    wxPanel* statusPanel = new wxPanel(this, ID_StatusPanel, wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    statusPanel->SetBackgroundColour(wxColour(255, 255, 255));
    statusPanel->SetForegroundColour(wxColour(0, 0, 0));

    wxStaticText* statusBar = new wxStaticText(statusPanel, ID_StatusText, "NAO INICIADO", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER);
    statusBar->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    wxBoxSizer* statusPanelSizer = new wxBoxSizer(wxHORIZONTAL);
    statusPanelSizer->Add(statusBar, 1, wxALIGN_CENTER_VERTICAL | wxALL, 10);
    statusPanel->SetSizer(statusPanelSizer);
    statusPanel->SetMinSize(wxSize(-1, 40));

    sizer->Add(statusPanel, 0, wxEXPAND | wxALL, 10);

    wxButton* startButton = new wxButton(this, ID_StartButton, "Iniciar");
    startButton->Bind(wxEVT_BUTTON, &MainFrame::OnStartButtonClicked, this);
    sizer->Add(startButton, 0, wxALIGN_RIGHT | wxALL, 10);

    SetSizer(sizer);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(
        "The Prografo is a software tool designed to find maximum independent sets in a graph using various algorithms. It provides options to find maximum independent sets and maximal independent sets, and it can read graph input in DIMACS format.",
        "About Prografo", 
        wxOK | wxICON_INFORMATION
    );
}

void MainFrame::OnFileInputButtonClicked(wxCommandEvent& event) 
{
    wxButton* fileInputButton = wxDynamicCast(FindWindowById(ID_FileInputButton), wxButton);

    if (fileInputButton) {
        wxFileDialog openFileDialog(this, "Selecionar arquivo", "", "", "Todos os arquivos (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

        if (openFileDialog.ShowModal() == wxID_CANCEL) {
            return;
        }

        selectedFilePath = openFileDialog.GetPath();

        fileInputButton->SetLabel(wxFileNameFromPath(selectedFilePath));
    }
}


void MainFrame::OnExecutionTypeSelected(wxCommandEvent& event) 
{
    wxRadioBox* radioBox = dynamic_cast<wxRadioBox*>(event.GetEventObject());
    if (radioBox) 
    {
        int selection = radioBox->GetSelection();
        selectedExecutionType = executionTypes[selection];
    }
}

void MainFrame::UpdateStatus(const wxString& label, const wxColour& textColour, const wxColour& panelColour) 
{
    wxStaticText* statusBarText = wxDynamicCast(FindWindowById(ID_StatusText), wxStaticText);
    wxPanel* statusPanel = wxDynamicCast(FindWindowById(ID_StatusPanel), wxPanel);

    if (statusBarText && statusPanel) {
        statusBarText->SetLabel(label);
        statusBarText->SetForegroundColour(textColour);
        statusPanel->SetBackgroundColour(panelColour);

        statusBarText->SetSize(statusPanel->GetSize());
        statusBarText->SetMinSize(wxSize(-1, -1));
        statusBarText->SetWindowStyle(wxALIGN_CENTER);

        statusPanel->Refresh();
        statusPanel->Update();
    }
}

void MainFrame::OnStartButtonClicked(wxCommandEvent& event) 
{
    if (selectedFilePath.empty()) {
        UpdateStatus("ERRO: selecione um arquivo", wxColour(255, 255, 255), wxColour(255, 0, 0));
    } else {
        UpdateStatus("EM PROGRESSO", wxColour(255, 255, 255), wxColour(0, 0, 255));

        wxCharBuffer filePathBuffer = selectedFilePath.ToUTF8();
        char* filePath = filePathBuffer.data();

        wxCharBuffer executionTypeBuffer = selectedExecutionType.ToUTF8();
        char* executionType = executionTypeBuffer.data();

        int result = run_prografo(executionType, filePath);

        if (result == 0) {
            UpdateStatus("CONCLUIDO", wxColour(255, 255, 255), wxColour(0, 255, 0));
        } else {
            UpdateStatus("ERRO: algo deu errado", wxColour(255, 255, 255), wxColour(255, 0, 0));
        }
    }
}
