#include<gtk/gtk.h>
#include<stdlib.h>

int
main(int argc,char *argv[])
{

// EXIT_SUCCESS
// EXIT_FAILURE
    GtkWidget *window;
    gtk_init(&argc,&argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_widget_show(window);
    gtk_main();
    return EXIT_SUCCESS;
}