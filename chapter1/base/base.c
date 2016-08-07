#include<gtk/gtk.h>
// 这是每个gtk+2.0 程序都要包含的头文件。


#include<stdlib.h>
// EXIT_SUCCESS
// EXIT_FAILURE


int
main(int argc,char *argv[])
{

// EXIT_SUCCESS
// EXIT_FAILURE
    GtkWidget *window;
    // 窗口控件指针。
    // GtkWidget是 GTK+2.0控件类型，几乎所有的GTK+2.0控件都用这一类型声明。

    gtk_init(&argc,&argv);
   //初始化命令行参数，这在GTK+2.0程序中是必须的。不管是否用到它。



    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // 参数 GTK_WINDOW_TOPLEVEL 指明窗口的类型为最上层的主窗口,它
    // 最常用。还可以取另一个值 GTK_WINDOW_POPUP 指明窗口的类型为弹出式的无边框的
    // 窗口.

    gtk_widget_show(window);// 显示控件。参数是要显示的控件的指针。

	g_print("hello world");

    gtk_main();
    // 他是GTK+2.0的主事件循环。每一个GTK+2.0程序都要有一个。
    // 否则程序就无法运行。

    // 所谓的事件循环是指GUI程序运行时等待来自外部用户发出的事件，比如
	// 键入或者鼠标移动。GTK+2.0将这些事件包装成信号。用户再根据信号的功能编写
	// 相应的回调函数来处理这些事件。

/*

CC = gcc
all:
	$(CC) -o base base.c `pkg-config --cflags --libs gtk+-2.0`
*/

// 命令行中的'pkg-config --cflags --libs gtk+-2.0',它向编译器指出了包含
// 文件的路径,
//动态链接库路径和要链接哪些动态链接库。 pkg-config 是 GTK+2.0 和 GNOME2
// 系统必备的软件包配置和管理工具,可以在命令中直接运行

    return EXIT_SUCCESS;
}

