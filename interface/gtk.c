#include <gtk/gtk.h>

static void file_selected(GtkWidget *widget, gpointer data) {
    GtkFileChooserButton *file_chooser = GTK_FILE_CHOOSER_BUTTON(widget);
    const gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_chooser));
    g_print("Arquivo selecionado: %s\n", filename);
}

static void execute_type_selected(GtkWidget *widget, gpointer data) {
    GtkFileChooserButton *file_chooser = GTK_FILE_CHOOSER_BUTTON(data);
    const gchar *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_chooser));
    const gchar *type = gtk_button_get_label(GTK_BUTTON(widget));
    g_print("Arquivo selecionado: %s\n", filename);
    g_print("Opção de execução selecionada: %s\n", type);
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *label_title;
    GtkWidget *label_subtitle;
    GtkWidget *file_chooser;
    GtkWidget *label_execution;
    GtkWidget *button_box;
    GtkWidget *button_a;
    GtkWidget *button_b;
    GtkWidget *button_c;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Escolher Arquivo");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 250);

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
    gtk_widget_set_name(box, "main-window");  // Aplicando classe CSS

    // Título
    label_title = gtk_label_new("Prografo");
    gtk_box_pack_start(GTK_BOX(box), label_title, TRUE, TRUE, 0);
    gtk_widget_set_halign(label_title, GTK_ALIGN_START);
    gtk_widget_set_name(label_title, "label-title");  // Aplicando classe CSS

    // Subtítulo
    label_subtitle = gtk_label_new("Selecione o grafo a ser executado no formato dimacs (.col)");
    gtk_box_pack_start(GTK_BOX(box), label_subtitle, TRUE, TRUE, 0);
    gtk_widget_set_halign(label_subtitle, GTK_ALIGN_START);
    gtk_widget_set_name(label_subtitle, "label-subtitle");  // Aplicando classe CSS

    // Botão de seleção de arquivo
    file_chooser = gtk_file_chooser_button_new("Selecione um arquivo", GTK_FILE_CHOOSER_ACTION_OPEN);
    g_signal_connect(file_chooser, "file-set", G_CALLBACK(file_selected), NULL);
    gtk_box_pack_start(GTK_BOX(box), file_chooser, TRUE, TRUE, 0);
    gtk_widget_set_name(file_chooser, "file-chooser");  // Aplicando classe CSS

    // Título "Tipos de execução"
    label_execution = gtk_label_new("Tipos de execução");
    gtk_box_pack_start(GTK_BOX(box), label_execution, TRUE, TRUE, 0);
    gtk_widget_set_halign(label_execution, GTK_ALIGN_START);
    gtk_widget_set_name(label_execution, "label-execution");

    // Box para os botões de execução
    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_box_pack_start(GTK_BOX(box), button_box, TRUE, TRUE, 0);

    // Botões de execução
    button_a = gtk_button_new_with_label("-a");
    g_signal_connect(button_a, "clicked", G_CALLBACK(execute_type_selected), file_chooser);
    gtk_container_add(GTK_CONTAINER(button_box), button_a);
    gtk_widget_set_name(button_a, "button-style");  // Aplicando classe CSS

    button_b = gtk_button_new_with_label("-b");
    g_signal_connect(button_b, "clicked", G_CALLBACK(execute_type_selected), file_chooser);
    gtk_container_add(GTK_CONTAINER(button_box), button_b);
    gtk_widget_set_name(button_b, "button-style");  // Aplicando classe CSS

    button_c = gtk_button_new_with_label("-c");
    g_signal_connect(button_c, "clicked", G_CALLBACK(execute_type_selected), file_chooser);
    gtk_container_add(GTK_CONTAINER(button_box), button_c);
    gtk_widget_set_name(button_c, "button-style");  // Aplicando classe CSS

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("treinaweb.filechooser", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
