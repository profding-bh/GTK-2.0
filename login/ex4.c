#include<gtk/gtk.h>
#include<stdlib.h>


GtkWidget *window;
GtkWidget *table;
GtkWidget *button;
GtkWidget *entry;
GtkWidget *label;

int 
main(int argc,char *argv[])
{

	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("Table example",-1,NULL,NULL,NULL)
						);

	// width & height
	gtk_widget_set_usize(window,260,150);
	// x & y
	gtk_widget_set_uposition(window,300,300);

	table = gtk_table_new(2,2,FALSE);
	gtk_container_add(GTK_CONTAINER(window),table);
	

    button =  gtk_button_new_with_label(
	g_locale_to_utf8("Button",-1,NULL,NULL,NULL)
		);

	entry = gtk_entry_new();

	label = gtk_label_new(
			g_locale_to_utf8("This is label 1",-1,NULL,NULL,NULL));


	// 放置
	gtk_table_attach(GTK_TABLE(table),button,0,1,0,1,
				(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(0),2,5);

	gtk_table_attach(GTK_TABLE(table),entry,0,1,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),2,10);
	
	gtk_table_attach(GTK_TABLE(table),label,1,2,0,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),2,5);

	// 显示窗口中的所有元件
	gtk_widget_show_all(window);


	//直接引用g_signal_connect宏,退出
    g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(gtk_main_quit),NULL);
	
	// 消息主循环
	gtk_main();
	return 0;
}


