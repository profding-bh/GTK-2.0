#include<gtk/gtk.h>
#include<stdlib.h>



GtkWidget *window;
GtkWidget *button;

int i = 0;

char text[50];
char a[50] = "You have clicked ";


void
on_clicked(GtkWidget *widget,gpointer data)
{
	i++;
	
	gcvt((float)i,3,text);///
	strcat(a,text);	
	strcat(a," times");
	gtk_button_set_label(GTK_BUTTON(button),a);
	a[17]= '\0';
}



int 
main(int argc,char *argv[])
{

	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("Button",-1,NULL,NULL,NULL)
						);

	// width & height
	gtk_widget_set_usize(window,250,150);
	// x & y
	gtk_widget_set_uposition(window,300,300);

	// 按钮
	button = gtk_button_new_with_label(
				g_locale_to_utf8("You have Clicked 0 times",-1,NULL,NULL,NULL));


	gtk_container_add(GTK_CONTAINER(window),button);

	// 显示窗口中的所有元件
	gtk_widget_show_all(window);

	//直接引用g_signal_connect宏,退出
    g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(gtk_main_quit),NULL);
	
  	g_signal_connect(G_OBJECT(button),"clicked"
            ,G_CALLBACK(on_clicked),NULL);
	// 消息主循环
	gtk_main();
	return 0;
}


