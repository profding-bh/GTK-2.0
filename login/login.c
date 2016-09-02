/*
 ===============================================================================
        Filename:  login.c
     	Description:  login interface
        Version:  1.0
        Created:  2016年09月02日 15时04分12秒
        Revision:  1.0
        Compiler:  gcc
        Author:  profding
    	Organization:  G306
 ===============================================================================
 */
/*

Q:
How to compile & run?

A:
the Makefile is below:

CC = gcc
all:
	$(CC) -o login login.c `pkg-config --cflags --libs gtk+-2.0`
.PHONY:clean
clean:
	rm login



Q：
How to install the gtk+2.0?

A:
安装GTK环境只要安装一个libgtk2.0-dev就可以了，

sudo apt-get install libgtk2.0-dev

而安装gnome开发环境的话，需要装gnome-core-devel，它包含GTK开发包。 
但在一般情况下，我们需要有一个ide开发环境，需要帮助文件，于是我们安装:
sudo apt-get install gnome-devel gnome-devel-docs

*/
#include<gtk/gtk.h>


int 
main(int argc,char *argv[])
{
	GtkWidget *window;
	GtkWidget *table;// 和ios相比，是多出来的，ios没有这种界面布局控件。
	GtkWidget *label1;
	GtkWidget *label2;
	GtkWidget *entry1;
	GtkWidget *entry2;
	GtkWidget *button1;
	GtkWidget *button2;
	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("用户登录",-1,NULL,NULL,NULL)
						);
	// g_locale_to_utf8()支持中文字符显示。
	// 表格：3行2列，单元格大小会根据单元格中的控件大小自动调整。
	table = gtk_table_new(3,2,FALSE);

	// 标签
	label1 = gtk_label_new(g_locale_to_utf8("用户名",-1,NULL,NULL,NULL));
	gtk_widget_set_size_request(label1,45,15);
	label2 = gtk_label_new(g_locale_to_utf8("密码",-1,NULL,NULL,NULL));
	gtk_widget_set_size_request(label2,30,15);


	// 文本框
	entry1 = gtk_entry_new();
	entry2 = gtk_entry_new();

	// 按钮
	button1 = gtk_button_new_with_label(
				g_locale_to_utf8("取消",-1,NULL,NULL,NULL));
	button2 = gtk_button_new_with_label(
				g_locale_to_utf8("确定",-1,NULL,NULL,NULL));

	// 将表格添加到窗口中，因为表格也是一个控件，自然要添加到容器中。
	gtk_container_add(GTK_CONTAINER(window),table);
	// 类似于controller的self.view

	// 将6个元件添加到表格相应的位置中。
	gtk_table_attach(GTK_TABLE(table),label1,0,1,0,1,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),20,10);

	gtk_table_attach(GTK_TABLE(table),entry1,1,2,0,1,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),10,10);

	gtk_table_attach(GTK_TABLE(table),label2,0,1,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),20,10);

	gtk_table_attach(GTK_TABLE(table),entry2,1,2,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),10,10);

	gtk_table_attach(GTK_TABLE(table),button1,0,1,2,3,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),20,10);

	gtk_table_attach(GTK_TABLE(table),button2,1,2,2,3,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),10,10);

	// 依次显示窗口中的所有元件
	gtk_widget_show(window);
	gtk_widget_show(table);
	gtk_widget_show(label1);
	gtk_widget_show(label2);
	gtk_widget_show(entry1);
	gtk_widget_show(entry2);
	gtk_widget_show(button1);
	gtk_widget_show(button2);


	//直接引用g_signal_connect宏,退出
    g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(gtk_main_quit),NULL);
	
	// 消息主循环
	gtk_main();
	return 0;
}


