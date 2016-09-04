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





int 
main(int argc,char *argv[])
{

	
	GtkWidget *window;

	GtkWidget *hpaned;// 和ios相比，是多出来的，ios没有这种界面布局控件。


	GtkWidget *label1;
	GtkWidget *label2;

	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("Linux & Windows",-1,NULL,NULL,NULL)
						);
	// g_locale_to_utf8()支持中文字符显示。
	
	hpaned = gtk_hpaned_new();

/*
和ios相比，可以省掉设置x,y,width,height这么恶心的事

*/

	// 标签
	label1 = gtk_label_new(
			g_locale_to_utf8("Linux是多用户多任务OS，而Windows是单用户多任务\
\nLinux 和windows都支持多种文件系统\
\nLinux 和windows都支持多种物理设备端口\
\nLinux 和windows都支持多种网络协议",-1,NULL,NULL,NULL));

	label2 = gtk_label_new(
			g_locale_to_utf8("Linux的应用目标是网络而不是打印，\
\n可选的GUI\
\nLinux不使用文件名扩展来识别文件的类型\
\nLinux 的命令和选项都区分大小写",-1,NULL,NULL,NULL));





	
	gtk_container_add(GTK_CONTAINER(window),hpaned);
	



	// 将2个元件添加到
	 gtk_paned_pack1(GTK_PANED(hpaned),label1,TRUE,TRUE);

	 gtk_paned_pack2(GTK_PANED(hpaned),label2,TRUE,TRUE);


	 gtk_paned_set_position(GTK_PANED(hpaned),40);


	// 显示窗口中的所有元件
	gtk_widget_show_all(window);

	//退出
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

