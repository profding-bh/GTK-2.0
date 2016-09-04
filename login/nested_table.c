#include<gtk/gtk.h>
#include<stdio.h>


// 注册回调
void
on_clicked(GtkWidget *widget,gpointer data)
{
	printf("调用注册接口\n");
}

// 登录回调
void
on_clicked2(GtkWidget *widget,gpointer data)
{
	printf("调用登录接口\n");
}

// 登录回调3
void
on_clicked3(GtkWidget *widget,gpointer data)
{
	printf("调用登录接口33333\n");
}





int 
main(int argc,char *argv[])
{

	
	GtkWidget *window;

	GtkWidget *table1;// 和ios相比，是多出来的，ios没有这种界面布局控件。
	GtkWidget *table2;


	GtkWidget *entry1;
	GtkWidget *entry2;
	GtkWidget *entry3;
	GtkWidget *entry4;

	GtkWidget *label1;
	GtkWidget *label2;
	GtkWidget *label3;
	GtkWidget *label4;
	GtkWidget *label5;


	GtkWidget *button1;
	GtkWidget *button2;

	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("用户信息",-1,NULL,NULL,NULL)
						);
	// g_locale_to_utf8()支持中文字符显示。
	// 表格：4行4列，单元格大小会根据单元格中的控件大小自动调整。
	table1 = gtk_table_new(4,4,FALSE);
	// 表格：1行2列
	table2 = gtk_table_new(1,2,FALSE);

/*
和ios相比，可以省掉设置x,y,width,height这么恶心的事

*/

	// 标签
	label1 = gtk_label_new(
			g_locale_to_utf8("我的信息",-1,NULL,NULL,NULL));
	label2 = gtk_label_new(
			g_locale_to_utf8("用户名：",-1,NULL,NULL,NULL));
	label3 = gtk_label_new(
			g_locale_to_utf8("密码：",-1,NULL,NULL,NULL));
	label4 = gtk_label_new(
			g_locale_to_utf8("电子邮件：",-1,NULL,NULL,NULL));
	label5 = gtk_label_new(
			g_locale_to_utf8("详细地址：",-1,NULL,NULL,NULL));



	// 文本框
	entry1 = gtk_entry_new();	
	entry2 = gtk_entry_new();
	entry3 = gtk_entry_new();
	entry4 = gtk_entry_new();



	// 按钮
	button1 = gtk_button_new_with_label(
				g_locale_to_utf8("注册",-1,NULL,NULL,NULL));
	button2 = gtk_button_new_with_label(
				g_locale_to_utf8("登录",-1,NULL,NULL,NULL));

	// 将表格添加到窗口中，因为表格也是一个控件，自然要添加到容器中。
	gtk_container_add(GTK_CONTAINER(window),table1);
	



	// 将10个元件添加到表格1相应的位置中。
	gtk_table_attach(GTK_TABLE(table1),label1,0,3,0,1,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);

	gtk_table_attach(GTK_TABLE(table1),table2,3,4,0,1,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),0,5);

	gtk_table_attach(GTK_TABLE(table1),label2,0,1,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);

	gtk_table_attach(GTK_TABLE(table1),entry1,1,2,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);

	gtk_table_attach(GTK_TABLE(table1),label3,2,3,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);

	gtk_table_attach(GTK_TABLE(table1),entry2,3,4,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);

	gtk_table_attach(GTK_TABLE(table1),label4,0,1,2,3,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);

	gtk_table_attach(GTK_TABLE(table1),entry3,1,4,2,3,
				(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(0),5,5);

	gtk_table_attach(GTK_TABLE(table1),label5,0,1,3,4,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);

	gtk_table_attach(GTK_TABLE(table1),entry4,1,4,3,4,
				(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(0),5,5);


	// 将2个按钮添加到表格2中。
	gtk_table_attach(GTK_TABLE(table2),button1,0,1,0,1,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),2,5);

	gtk_table_attach(GTK_TABLE(table2),button2,1,2,0,1,
				(GtkAttachOptions)(GTK_FILL),(GtkAttachOptions)(0),2,5);

	// 显示窗口中的所有元件
	gtk_widget_show_all(window);


	//为注册按钮添加回调函数
    g_signal_connect(G_OBJECT(button1),"clicked"
            ,G_CALLBACK(on_clicked),window);
	

	//为登录按钮添加回调函数3
    g_signal_connect(G_OBJECT(button2),"clicked"
            ,G_CALLBACK(on_clicked3),window);

	//为登录按钮添加回调函数
    g_signal_connect(G_OBJECT(button2),"clicked"
            ,G_CALLBACK(on_clicked2),window);

	/*
	
    */


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

