
#include<gtk/gtk.h>
#include<stdlib.h>



GtkWidget *window;
GtkWidget *table;// 和ios相比，是多出来的，ios没有这种界面布局控件。
GtkWidget *label;
GtkWidget *entry;
GtkWidget *button;

char text[50];


void
on_clicked(GtkWidget *widget,gpointer data)
{
	// 获取文本框的内容，并将其复制到text字符数组中
	strcpy(text,gtk_entry_get_text(GTK_ENTRY(entry)));
	printf("输入的字符串是：%s\n",text);
}





int 
main(int argc,char *argv[])
{

	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("文本框的使用",-1,NULL,NULL,NULL)
						);
	// g_locale_to_utf8()支持中文字符显示。
	// 表格：3行2列，单元格大小会根据单元格中的控件大小自动调整。
	table = gtk_table_new(3,2,FALSE);

	// 标签
	label = gtk_label_new(
			g_locale_to_utf8("请在这里输入文本：",-1,NULL,NULL,NULL));


	// 文本框
	entry = gtk_entry_new_with_max_length(50);


	// 按钮
	button = gtk_button_new_with_label(
				g_locale_to_utf8("提交",-1,NULL,NULL,NULL));


	// 将表格添加到窗口中，因为表格也是一个控件，自然要添加到容器中。
	gtk_container_add(GTK_CONTAINER(window),table);
	// 类似于controller的self.view

	// 将3个元件添加到表格相应的位置中。
	gtk_table_attach(GTK_TABLE(table),label,0,1,0,1,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),10,10);

	gtk_table_attach(GTK_TABLE(table),entry,0,2,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),10,10);

	gtk_table_attach(GTK_TABLE(table),button,1,2,2,3,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),10,10);

	// 显示窗口中的所有元件
	gtk_widget_show_all(window);


	//为提交按钮添加回调函数
    g_signal_connect(G_OBJECT(button),"clicked"
            ,G_CALLBACK(on_clicked),window);
	
	//直接引用g_signal_connect宏,退出
    g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(gtk_main_quit),NULL);
	
	// 消息主循环
	gtk_main();
	return 0;
}

/*
g_signal_connect()
在点击“提交”按钮时，产生来相应的信号。
系统自动调用相应的信号处理函数。 
*/

