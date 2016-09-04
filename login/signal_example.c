#include<gtk/gtk.h>
#include<stdlib.h>



int i = 0;
	
GtkWidget *window;
GtkWidget *table;
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
GtkWidget *button;


// 注册回调
void
on_clicked(GtkWidget *widget,gpointer data)
{
	char a[20];
	i++;
	gcvt((float)i,3,a);
	gtk_label_set_text(GTK_LABEL(label2),a);
}

int 
main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("信号与事件",-1,NULL,NULL,NULL)
						);
	// g_locale_to_utf8()支持中文字符显示。	
	gtk_container_border_width(GTK_CONTAINER(window),20);


	table = gtk_table_new(2,3,FALSE);
	gtk_container_add(GTK_CONTAINER(window),table);

	// 标签
	label1 = gtk_label_new(
			g_locale_to_utf8("单击按钮第",-1,NULL,NULL,NULL));
	label2 = gtk_label_new(
			g_locale_to_utf8("0",-1,NULL,NULL,NULL));
	label3 = gtk_label_new(
			g_locale_to_utf8("次",-1,NULL,NULL,NULL));

	// 按钮
	button = gtk_button_new_with_label(
				g_locale_to_utf8("计数",-1,NULL,NULL,NULL));

	// 将元件放入表格
	gtk_table_attach(GTK_TABLE(table),label1,0,1,0,1,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),0,10);

	gtk_table_attach(GTK_TABLE(table),label2,1,2,0,1,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),0,10);

	gtk_table_attach(GTK_TABLE(table),label3,2,3,0,1,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),0,10);

	gtk_table_attach(GTK_TABLE(table),button,2,3,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),0,10);

	// 显示窗口中的所有元件
	gtk_widget_show_all(window);

	//退出-->信号事件处理必须放在主循环之前。
    g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(gtk_main_quit),NULL);
	// 计数
	g_signal_connect(G_OBJECT(button),"clicked"
            ,G_CALLBACK(on_clicked),NULL);

	// 消息主循环
	gtk_main();
	return 0;
}


