
#include<gtk/gtk.h>
#include<stdlib.h>



GtkWidget *window;
GSList *group = NULL;
GtkWidget *check;
GtkWidget *radio;
GtkWidget *vbox;

int 
main(int argc,char *argv[])
{

	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("Check and Radio",-1,NULL,NULL,NULL)
						);

	// width & height
	gtk_widget_set_usize(window,250,220);
	// x & y
	gtk_widget_set_uposition(window,300,300);

	gtk_container_border_width(GTK_CONTAINER(window),40);
	// 复选
/*
	check = gtk_check_button_new_with_label(
	g_locale_to_utf8("Teacher",-1,NULL,NULL,NULL));
	gtk_container_add(GTK_CONTAINER(window),check);

	check = gtk_check_button_new_with_label(
	g_locale_to_utf8("Student",-1,NULL,NULL,NULL));
	// 
	gtk_container_add(GTK_CONTAINER(window),check);
	

(ex7:4558): Gtk-WARNING **: 
Attempting to add a widget with type GtkCheckButton to a GtkWindow,
 but as a GtkBin subclass a GtkWindow can only contain one widget at a time;
 it already contains a widget of type GtkCheckButton

*/
	
	vbox = gtk_vbox_new(FALSE,1);
   gtk_widget_set_usize(vbox,100,120);
/*

如何设置vbox's  width & hight?
gtk_widget_set_usize(vbox,100,120);好像没有用？？？

*/
	gtk_container_add(GTK_CONTAINER(window),vbox);


	// 复选
	check = gtk_check_button_new_with_label(
	g_locale_to_utf8("Teacher",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(vbox),check,FALSE,FALSE,2);
	  
	check = gtk_check_button_new_with_label(
	g_locale_to_utf8("Student",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(vbox),check,FALSE,FALSE,2);

	// 单选
	radio = gtk_radio_button_new_with_label(NULL,
	g_locale_to_utf8("Chinese",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(vbox),radio,FALSE,FALSE,2);

	group= gtk_radio_button_group(GTK_RADIO_BUTTON(radio));
	radio = gtk_radio_button_new_with_label(group,
	g_locale_to_utf8("Math",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(vbox),radio,FALSE,FALSE,2);

	group= gtk_radio_button_group(GTK_RADIO_BUTTON(radio));
	radio = gtk_radio_button_new_with_label(group,
	g_locale_to_utf8("English",-1,NULL,NULL,NULL));
	gtk_box_pack_start(GTK_BOX(vbox),radio,FALSE,FALSE,2);

	
	// 显示窗口中的所有元件
	gtk_widget_show_all(window);
	//直接引用g_signal_connect宏,退出
    g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(gtk_main_quit),NULL);
	// 消息主循环
	gtk_main();
	return 0;
}


