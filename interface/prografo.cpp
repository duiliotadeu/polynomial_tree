#include <wx/wx.h>
#include <wx/filepicker.h>
#include <wx/tglbtn.h>


class PrografoApp : public wxApp {
public:
    virtual bool OnInit() {
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Prografo", wxDefaultPosition, wxSize(400, 330));

        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
        frame->SetSizer(sizer);

        wxStaticText* labelTitle = new wxStaticText(frame, wxID_ANY, "Prografo");
        labelTitle->SetForegroundColour(*wxBLACK);
        sizer->Add(labelTitle, 0, wxALL | wxEXPAND, 5);

        wxStaticText* labelFileChooser = new wxStaticText(frame, wxID_ANY, "Selecione o grafo no formato dimacs (.col):");
        labelFileChooser->SetForegroundColour(*wxBLACK);
        sizer->Add(labelFileChooser, 0, wxALL | wxEXPAND, 5);

        wxFilePickerCtrl* fileChooser = new wxFilePickerCtrl(frame, wxID_ANY, wxEmptyString, wxEmptyString, "All files (*.*)|*.*",
            wxDefaultPosition, wxDefaultSize, wxFLP_OPEN);
        sizer->Add(fileChooser, 0, wxALL | wxEXPAND, 5);

        wxStaticText* labelExecutionType = new wxStaticText(frame, wxID_ANY, "Tipo de execução:");
        labelExecutionType->SetForegroundColour(*wxBLACK);
        sizer->Add(labelExecutionType, 0, wxALL | wxEXPAND, 5);

        wxBoxSizer* buttonBox = new wxBoxSizer(wxHORIZONTAL);
        sizer->Add(buttonBox, 0, wxALL | wxEXPAND, 5);

        wxToggleButton* radioA = new wxToggleButton(frame, wxID_ANY, "-a");
        buttonBox->Add(radioA, 0, wxALL, 5);

        wxToggleButton* radioB = new wxToggleButton(frame, wxID_ANY, "-b");
        buttonBox->Add(radioB, 0, wxALL, 5);

        wxToggleButton* radioC = new wxToggleButton(frame, wxID_ANY, "-c");
        buttonBox->Add(radioC, 0, wxALL, 5);

        wxToggleButton* radioD = new wxToggleButton(frame, wxID_ANY, "-d");
        buttonBox->Add(radioD, 0, wxALL, 5);

        wxStaticText* labelStatus = new wxStaticText(frame, wxID_ANY, "Status");
        labelStatus->SetForegroundColour(*wxBLACK);
        sizer->Add(labelStatus, 0, wxALL | wxEXPAND, 5);

        wxStatusBar* statusBar = new wxStatusBar(frame, wxID_ANY);
        sizer->Add(statusBar, 0, wxALL | wxEXPAND, 5);
        statusBar->PushStatusText("NÃO INICIADO");

        wxButton* startButton = new wxButton(frame, wxID_ANY, "Iniciar");
        sizer->Add(startButton, 0, wxALIGN_RIGHT | wxALL, 5);

        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(PrografoApp);
