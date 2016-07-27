#include<gtk/gtk.h>
// 这是每个gtk+2.0 程序都要包含的头文件。


#include<stdlib.h>
// EXIT_SUCCESS
// EXIT_FAILURE



/*
表格容器:

盒状容器只能容纳一行或一列控件

如何容纳多行多列控件呢？

1）向盒状容器中再添加
盒状容器。对,这是创建多行多列控件布局的很好的方法。

2）还有一种方法就是用表格容器
(GtkTable)控件。


表格容器是一种能容纳多行多列控件且简单易用的容器,它提供了坐标方式表示控件
所要摆放的空间的方法,使按行列方式排列多个控件变得更加简单。




框架控件：

*/




gint count = 1;

// 声明回调函数on_delete_event
void on_delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)
{
  gtk_main_quit();// 还是需要调用系统的。
}




void
on_button_clicked(GtkWidget *button,gpointer userdata)
{
    g_print("你好,这是Hello功能的测试.");
g_print("Hello . This is a test . ");
g_print("%d\n",(gint)userdata);
g_print("%d\n",count);
count = count + 1 ;
}


int
main(int argc,char *argv[])
{

// EXIT_SUCCESS
// EXIT_FAILURE
    GtkWidget *window;
    GtkWidget *button;
	GtkWidget *frame;//框架控件
GtkWidget *table;

	gchar *title = "表格容器";


    gtk_init(&argc,&argv);
   //初始化命令行参数，这在GTK+2.0程序中是必须的。不管是否用到它。

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(on_delete_event),NULL);

    gtk_window_set_title(GTK_WINDOW(window),title);
 gtk_window_set_default_size(GTK_WINDOW(window),200,300);

    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    gtk_container_set_border_width(GTK_CONTAINER(window),20);

	frame = gtk_frame_new("请注意下列按钮的排列");
	gtk_container_add(GTK_CONTAINER(window),frame);

	table = gtk_table_new(4,4,FALSE);

gtk_container_set_border_width(GTK_CONTAINER(table),10);

gtk_table_set_row_spacings(GTK_TABLE(table),5);

gtk_table_set_col_spacings(GTK_TABLE(table),5);

gtk_container_add(GTK_CONTAINER(frame),table);


	button = gtk_button_new();
	

	gtk_table_attach(GTK_TABLE(table),button,0,1,0,1,GTK_FILL,GTK_FILL,0,0);
//0,0-1,1

	button = gtk_button_new();
	gtk_table_attach(GTK_TABLE(table),button,1,3,1,3,GTK_FILL,GTK_FILL,0,0);


    button = gtk_button_new();
	gtk_table_attach_defaults(GTK_TABLE(table),button,0,1,1,3);


button = gtk_button_new();
	gtk_table_attach_defaults(GTK_TABLE(table),button,1,3,0,1);


button = gtk_button_new();
	gtk_table_attach_defaults(GTK_TABLE(table),button,0,4,3,4);


button = gtk_button_new();
	gtk_table_attach_defaults(GTK_TABLE(table),button,3,4,0,3);


    gtk_widget_show_all(window);

    gtk_main();


    return EXIT_SUCCESS;
}


/*

框架控件(GtkFrame)和窗口一样是一种只能容纳一个控件的对象,但它不能象窗口那
样直接显示出来,这一点又和盒状容器一样,必须把它放到窗口中才能显示出来

框架控
件在 GTK+2.0 编程中主要起到美化、修饰窗口、规范控件的范围和提示的作用。可以用
gtk_frame _new 函数创建框架,参数是显示在框架上的标题文字
gtk_frame_new


gtk_table_new  
行数、列数
和是否均匀分布



gtk_table_attach_defaults
gtk_table_attach

它们的功
能都是向格状容器的指定区域中添加控件

GtkAttachOptions: GTK_EXPAND,可扩展的;GTK_SHRINK,可缩小的;GTK_FILL,可添充的。本例中取
值为 GTK_FILL。





*/
