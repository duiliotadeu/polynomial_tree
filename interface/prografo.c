#include <gtk/gtk.h>

const gchar *selected_execution_type = NULL;
const gchar *selected_file_path = NULL;

void apply_css(GtkWidget *widget, const char *css) {
    GtkCssProvider *provider = gtk_css_provider_new();
    GdkDisplay *display = gdk_display_get_default();
    GdkScreen *screen = gdk_display_get_default_screen(display);
    GtkStyleContext *context = gtk_widget_get_style_context(widget);

    gtk_css_provider_load_from_data(provider, css, -1, NULL);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    g_object_unref(provider);
}

static void file_selected(GtkWidget *widget, gpointer data) {
    GtkFileChooserButton *file_chooser = GTK_FILE_CHOOSER_BUTTON(widget);
    selected_file_path = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_chooser));
}

static void execute_type_selected(GtkWidget *widget, gpointer data) {
    selected_execution_type = gtk_button_get_label(GTK_BUTTON(widget));
}

// Callback para o botão "Iniciar"
static void start_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *status_bar = GTK_WIDGET(data);
    const gchar *message;
    
    if (selected_file_path != NULL && selected_execution_type != NULL) {
        const char *new_css = "#status-bar { background-color: #0078d4; color: white; font-weight: bold; }";
        apply_css(status_bar, new_css);
        message = g_strdup_printf("EM PROGRESSO");
    } 
    if (selected_execution_type == NULL) {
        const char *new_css = "#status-bar { background-color: red; color: white; font-weight: bold; }";
        apply_css(status_bar, new_css);
        message = "ERRO: selecione um tipo de execução.";
    }
    if (selected_file_path == NULL) {
        const char *new_css = "#status-bar { background-color: red; color: white; font-weight: bold; }";
        apply_css(status_bar, new_css);
        message = "ERRO: selecione um arquivo.";
    }

    gtk_statusbar_push(GTK_STATUSBAR(status_bar), 0, message);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *label_title;
    GtkWidget *label_file_chooser;
    GtkWidget *file_chooser;
    GtkWidget *label_execution_type;
    GtkWidget *button_box;
    GtkWidget *label_status;
    GtkWidget *status_bar;
    GtkWidget *start_button;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Prografo");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 200);

    GtkCssProvider *css_provider = gtk_css_provider_new();
    GError *error = NULL;
    gtk_css_provider_load_from_path(css_provider, "style.css", &error);
    if (error) {
        g_print("Erro ao carregar o arquivo CSS: %s\n", error->message);
        g_error_free(error);
    }
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box);

    // Título
    label_title = gtk_label_new("Prografo");
    gtk_box_pack_start(GTK_BOX(box), label_title, TRUE, TRUE, 0);
    gtk_widget_set_halign(label_title, GTK_ALIGN_START);
    gtk_widget_set_name(label_title, "label-title");

    // Título "Tipo de execução"
    label_file_chooser = gtk_label_new("Selecione o grafo no formato dimacs (.col):");
    gtk_box_pack_start(GTK_BOX(box), label_file_chooser, TRUE, TRUE, 0);
    gtk_widget_set_halign(label_file_chooser, GTK_ALIGN_START);
    gtk_widget_set_name(label_file_chooser, "label-description");

    // Botão de seleção de arquivo
    file_chooser = gtk_file_chooser_button_new("", GTK_FILE_CHOOSER_ACTION_OPEN);
    g_signal_connect(file_chooser, "file-set", G_CALLBACK(file_selected), NULL);
    gtk_box_pack_start(GTK_BOX(box), file_chooser, TRUE, TRUE, 0);
    gtk_widget_set_margin_top(GTK_WIDGET(file_chooser), 6); 
    gtk_widget_set_name(file_chooser, "file-chooser");

    // Título "Tipo de execução"
    label_execution_type = gtk_label_new("Tipo de execução:");
    gtk_box_pack_start(GTK_BOX(box), label_execution_type, TRUE, TRUE, 0);
    gtk_widget_set_halign(label_execution_type, GTK_ALIGN_START);
    gtk_widget_set_name(label_execution_type, "label-description");

    // Box para os botões de execução
    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_pack_start(GTK_BOX(box), button_box, TRUE, TRUE, 0);
    gtk_widget_set_name(button_box, "button-box");

    // Botões de execução (GtkToggleButton)
    GtkWidget *radio_a = gtk_toggle_button_new_with_label("-a");
    g_signal_connect(radio_a, "toggled", G_CALLBACK(execute_type_selected), NULL);
    gtk_container_add(GTK_CONTAINER(button_box), radio_a);
    gtk_widget_set_size_request(radio_a, 100, -1);
    gtk_widget_set_name(radio_a, "radio-button");

    GtkWidget *radio_b = gtk_toggle_button_new_with_label("-b");
    g_signal_connect(radio_b, "toggled", G_CALLBACK(execute_type_selected), NULL);
    gtk_container_add(GTK_CONTAINER(button_box), radio_b);
    gtk_widget_set_size_request(radio_b, 100, -1);
    gtk_widget_set_name(radio_b, "radio-button");

    GtkWidget *radio_c = gtk_toggle_button_new_with_label("-c");
    g_signal_connect(radio_c, "toggled", G_CALLBACK(execute_type_selected), NULL);
    gtk_container_add(GTK_CONTAINER(button_box), radio_c);
    gtk_widget_set_size_request(radio_c, 100, -1);
    gtk_widget_set_name(radio_c, "radio-button");

    GtkWidget *radio_d = gtk_toggle_button_new_with_label("-d");
    g_signal_connect(radio_d, "toggled", G_CALLBACK(execute_type_selected), NULL);
    gtk_container_add(GTK_CONTAINER(button_box), radio_d);
    gtk_widget_set_size_request(radio_d, 100, -1);
    gtk_widget_set_name(radio_d, "radio-button");

    // Título
    label_status = gtk_label_new("Status");
    gtk_box_pack_start(GTK_BOX(box), label_status, TRUE, TRUE, 0);
    gtk_widget_set_halign(label_status, GTK_ALIGN_START);
    gtk_widget_set_name(label_status, "label-status");

    // Barra de status
    status_bar = gtk_statusbar_new();
    gtk_box_pack_start(GTK_BOX(box), status_bar, TRUE, TRUE, 0);
    gtk_statusbar_push(GTK_STATUSBAR(status_bar), 0, "NÃO INICIADO");
    gtk_widget_set_name(status_bar, "status-bar");
    gtk_widget_set_margin_start(GTK_WIDGET(status_bar), 14);
    gtk_widget_set_margin_end(GTK_WIDGET(status_bar), 14);

    // Botão "Iniciar"
    start_button = gtk_button_new_with_label("Iniciar");
    g_signal_connect(start_button, "clicked", G_CALLBACK(start_button_clicked), status_bar);
    gtk_box_pack_start(GTK_BOX(box), start_button, TRUE, TRUE, 0);
    gtk_widget_set_name(start_button, "start-button");
    gtk_widget_set_margin_end(GTK_WIDGET(start_button), 16); 
    gtk_widget_set_margin_bottom(GTK_WIDGET(start_button), 16); 
    gtk_widget_set_margin_top(GTK_WIDGET(start_button), 10); 
    gtk_widget_set_halign(start_button, GTK_ALIGN_END);
    gtk_widget_set_size_request(start_button, 106, 20);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("ufrrj.prografo", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
