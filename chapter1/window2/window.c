#include<gtk/gtk.h>
// 这是每个gtk+2.0 程序都要包含的头文件。


#include<stdlib.h>
// EXIT_SUCCESS
// EXIT_FAILURE


// 声明回调函数on_delete_event
void on_delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)
{

  printf("我要退出了\n");
  // sleep(3);
  gtk_main_quit();// 还是需要调用系统的。
// 这里的思路告诉我们，系统的放在最后处理，在此之前，处理我们自己的需求。
// 可以在 on_delete_event 函数中
// 加入其他代码来处理程序开始时遗留的问题(如释放已分配的内存、保存程序配置等),还
// 可以询问用户是否真正退出程序运行。windows系统，点击关闭按钮，询问用户释放退出，
// 不就是这样做的吗！！
}



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


    // 为信号连接回调函数;
    // 为窗口或者控件加回调函数有2种方式
    //《1》一是直接调用已经有的函数（比如gtk_main_quit）,在窗口，或控件创建完成后
    //直接引用g_signal_connect宏。如下：
   // g_signal_connect(G_OBJECT(window),"delete_event"
   //         ,G_CALLBACK(gtk_main_quit),NULL);
//<2>第2种方式是： 先定义好回调函数，在窗口，或控件创建完成后
    //直接引用g_signal_connect宏。如下：


  g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(on_delete_event),NULL);

//  g_signal_connect宏的格式：
// 4 个参数：
// (1)连接的对象；就是要连接信号的控件的指针。（注意：必须是已创建完的控件的指针。）
// 需要G_OBJECT(）宏进行转换。G_OBJECT(window)
// (2)信号名称：就是要连接的信号名称。为字符串形式，用双引号。不同的控件拥有的信号名称是
// 不一样的。（这是必然的。）
// （3）回调函数：指信号发生时调用的函数。这里只用到函数的名称。需要用G_CALLBACK(）宏
// 进行转换。G_CALLBACK(on_delete_event)
// （4）传递给回调函数的参数。它的类型应该是gpointer.如果不是这一类型可以强制转换，
// 如果没有参数，则为NULL.这里只能传递1个参数。如果有多个参数，可以先将多个参数定义为
// 结构，再将此结构作为参数传递过来。（----see,思路都是一样的）。


// 回调函数的格式
// 不同的控件的信号不同，不同的信号的回调函数的格式也不同。
// 有一个规律，即多数回调函数是没有返回类型的。名称可以自定义。最好能表达
// 一定的意思。参数有多个。第一个参数是调用此回调函数的控件对象指针。
// 最后一个参数是用户传递给此回调函数的参数，而且固定为，gpointer类型。


/*

改变窗口外观的几个函数：
设定窗口的标题：
gtk_window_set_title(window,const gchar *title);


设定窗口的默认宽高：
gtk_window_set_default_size(window,int width,int height);

设定窗口的位置：(其实就是x,y坐标)
gtk_window_set_position(window,GtkWindowPosition position);


其中 position 可以取如下值:
GTK_WIN_POS_NONE  不固定
GTK_WIN_POS_CENTER 居中
GTK_WIN_POS_MOUSE  出现在鼠标位置
GTK_WIN_POS_CENTER_ALWAYS  窗口改变尺寸仍居中

GTK_WIN_POS_CENTER_ON_PARENT  居于父窗口的中部
*/






//GTK+2.0采用了一种信号/回调函数机制来处理窗口外部传来的事件、消息或信号。
//也就是先为窗口或控件定义一系列信号。在编程中引用信号名称为窗口或控件添加回调函数。
//当信号发生时，程序自动调用为信号连接的回调函数。
//窗口的信号有很多，
//'key_press_event' 在按键时发生
//‘foucs’ 在获得焦点时发生
//'delete_event'在窗口关闭时发生
//
//退出GTK+2.0程序要调用gtk_main_quit();函数。他的功能就是退出主循环。
//也就是结束程序的运行。
//
//
    gtk_window_set_title(GTK_WINDOW(window),"一个功能完善的窗口");
    gtk_window_set_default_size(GTK_WINDOW(window),500,100);
    gtk_window_set_position(GTK_WINDOW(window),
// GTK_WIN_POS_MOUSE
// GTK_WIN_POS_NONE
// GTK_WIN_POS_CENTER_ALWAYS
GTK_WIN_POS_CENTER_ON_PARENT
        );
    //GTK_WIN_POS_CENTER);



    gtk_widget_show(window);// 显示控件。参数是要显示的控件的指针。

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


/*

GTK+2.0控件是统一用GtkWidget类型来管理的。
gtk_button_new 创建一个不显示内容的按钮

gtk_button_new_with_label   创建一个显示文字的按钮



代码书写顺序：

先定义，再创建，再加回调函数。最后显示。


GTK+2.0的函数名称：
以gtk开头，用_连接。
第2个单词表示控件类型。比如：button,window.
再后面的相关的单词表示要做的动作。

例如：
gtk_控件类型_动作
gtk_button_new


容器：

GtkContainer — Base class for widgets which contain other widgets


GTK+2.0中的控件的摆放  采用了容器(Container)，这一概念。

即所有的GTK+2.0控件分成2种：一种是能容纳其他控件的容器。
另一种是不能容纳其他控件的非容器控件。


容器控件又分为能容纳多个控件的容器和 只能容纳一个控件的容器。



窗口控件也是一种容器。

GTK+2.0提供了与容器相关的操作函数，以gtk_container开头。

gtk_container_add： 将另一个控件加入到容器中。

void
gtk_container_add (GtkContainer *container,
                   GtkWidget *widget);

Adds widget to container . Typically used for simple containers such as GtkWindow, GtkFrame, or GtkButton; for more complicated layout containers such as GtkBox or GtkGrid, this function will pick default packing parameters that may not be correct. So consider functions such as gtk_box_pack_start() and gtk_grid_attach() as an alternative to gtk_container_add() in those cases. A widget may be added to only one container at a time; you can’t place the same widget inside two different containers.

Note that some containers, such as GtkScrolledWindow or GtkListBox, may add intermediate children between the added widget and the container.

Parameters
container
a GtkContainer
 
widget
a widget to be placed inside container



gtk_container_remove:移除

void
gtk_container_remove (GtkContainer *container,
                      GtkWidget *widget);

Removes widget from container . widget must be inside container . Note that container will own a reference to widget , and that this may be the last reference held; so removing a widget from its container can destroy that widget. If you want to use widget again, you need to add a reference to it before removing it from a container, using g_object_ref(). If you don’t want to use widget again it’s usually more efficient to simply destroy it directly using gtk_widget_destroy() since this will remove it from the container and help break any circular reference count cycles.

Parameters
container
a GtkContainer
 
widget
a current child of container



gpointer
g_object_ref (gpointer object);

Increases the reference count of object .

Parameters
object
a GObject. [type GObject.Object]
Returns
the same object . [type GObject.Object][transfer none]




GObject — The base object type

#define G_OBJECT(object)      (G_TYPE_CHECK_INSTANCE_CAST ((object), G_TYPE_OBJECT, GObject))

Casts a GObject or derived pointer into a (GObject*) pointer. Depending on the current debugging level, this function may invoke certain runtime checks to identify invalid casts.

Parameters
object
Object which is subject to casting.// 可以...的




另一个常用的与容器相关的函数是：
gtk_container_set_border_width




*/

