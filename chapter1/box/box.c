#include<gtk/gtk.h>
// 这是每个gtk+2.0 程序都要包含的头文件。


#include<stdlib.h>
// EXIT_SUCCESS
// EXIT_FAILURE



/*
盒状容器:




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
	GtkWidget *box;

	gchar *title = "排列按钮";


    gtk_init(&argc,&argv);
   //初始化命令行参数，这在GTK+2.0程序中是必须的。不管是否用到它。

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(on_delete_event),NULL);

    gtk_window_set_title(GTK_WINDOW(window),title);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window),20);

	box = gtk_hbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window),box);

	button = gtk_button_new_with_label("按钮一");
	gtk_box_pack_start(GTK_BOX(box),button,TRUE,TRUE,3);

button = gtk_button_new_with_label("按");
gtk_box_pack_end(GTK_BOX(box),button,FALSE,FALSE,3);

button = gtk_button_new_with_label("钮");
gtk_box_pack_end(GTK_BOX(box),button,FALSE,FALSE,3);

button = gtk_button_new_with_label("二");
gtk_box_pack_end(GTK_BOX(box),button,FALSE,FALSE,3);


	g_print("%d",gtk_box_get_homogeneous(GTK_BOX(box)));
    gtk_widget_show_all(window);

    gtk_main();


    return EXIT_SUCCESS;
}


/*

应该注意,基础的 GtkBox 类
是不能直接创建的。

gtk_hbox_new

GtkWidget *
gtk_hbox_new (gboolean homogeneous,
              gint spacing);


homogeneous
TRUE if all children are to be given equal space allotments.
 
spacing
the number of pixels to place by default between children.


GtkHBox is a container that organizes child widgets into a single row.


Use the GtkBox packing interface to determine the arrangement, spacing, width, and alignment of GtkHBox children.
All children are allocated the same height.
GtkHBox has been deprecated. You can use GtkBox instead, which is a very quick and easy change. If you have derived your own classes from GtkHBox, you can simply change the inheritance to derive directly from GtkBox. No further changes are needed, since the default value of the “orientation” property is GTK_ORIENTATION_HORIZONTAL. If you don’t need first-child or last-child styling, and want your code to be future-proof, the recommendation is to switch to GtkGrid instead of nested boxes. For more information about migrating to GtkGrid, see Migrating from other containers to GtkGrid.




gtk_vbox_new

GtkWidget *
gtk_vbox_new (gboolean homogeneous,
              gint spacing);

homogeneous
TRUE if all children are to be given equal space allotments.
 
spacing
the number of pixels to place by default between children.




盒状容器中添加控件也可以使用 gtk_container_add 函数,但这样只能加一个控件。

最好的办法是用 gtk_box_pack_*系列函数向盒状容器添加并排列控件,这样的函数一共有
4 个,分别是:gtk_box_pack_start、gtk_box_pack_end、gtk_box_pack_ start_defaults 和
gtk_box_pack_end_defaults。


gtk_box_pack_start


void
gtk_box_pack_start (GtkBox *box,
                    GtkWidget *child,
                    gboolean expand,
                    gboolean fill,
                    guint padding);
Parameters:
box
a GtkBox
 
child
the GtkWidget to be added to box
 
expand
TRUE if the new child is to be given extra space allocated to box . The extra space will be divided evenly between all children that use this option
 
fill
TRUE if space given to child by the expand option is actually allocated to child , rather than just padding it. This parameter has no effect if expand is set to FALSE. A child is always allocated the full height of a horizontal GtkBox and the full width of a vertical GtkBox. This option affects the other dimension
 
padding
extra space in pixels to put between this child and its neighbors, over and above the global amount specified by “spacing” property. If child is a widget at one of the reference ends of box , then padding pixels are also put between child and the reference edge of box


tk_box_pack_start、gtk_box_pack_end 分别表示按顺序从前到后依次排列控件和从后
到前依次排列控件。这两个函数都有 5 个参数,依次是 GTK_BOX(box),要容纳控件的容
器对象;button,被容纳控件的指针;是否扩展,是否添充和与前一控件的间隔。



gboolean
gtk_box_get_homogeneous (GtkBox *box);



另外,还要注意向容器添加控件的过程,即先创建窗口,再创建盒状容器,将盒状容
器加入到窗口中,最后创建按钮,将按钮排列到盒状容器中。一般创建后为控件的信号连
接回调函数,几乎每个 GTK+2.0 程序都是按照这样的顺序完成界面布局的。


A GtkVBox is a container that organizes child widgets into a single column.


GtkHBox is a container that organizes child widgets into a single row.

i.e.:
盒状容器只能容纳一行或一列控件




*/
