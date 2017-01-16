#include <gtk/gtk.h>


int main( int argc, char *argv[] )
{
        GtkWidget *window;
        GtkWidget *label;

        gtk_init(&argc, &argv);

        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    
        g_signal_connect(window, "destroy",G_CALLBACK(gtk_main_quit), NULL);

        gtk_container_set_border_width(GTK_CONTAINER(window), 10);

        label = gtk_label_new("Hello Ubuntu!");

     
  
        gtk_container_add(GTK_CONTAINER(window), label);

        gtk_widget_show_all(window);

        gtk_main();   /*进入主循环*/
        return(0);
}
