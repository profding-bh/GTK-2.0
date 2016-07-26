#include<gtk/gtk.h>
// 这是每个gtk+2.0 程序都要包含的头文件。
#include<stdlib.h>
#include<stdio.h>



/*

定时器在应用编程中，使用很广。
手机里的闹钟，幻灯片播放图片等应用都用到定时器。
定时器，每隔一段时间干一件事（程序里表现为调用一个函数）。

1)定时器的创建:

guint g_timeout_add(guint interval,GSourceFunc function,gpointer data);

interval:设置的时间间隔，以毫秒为单位。（1s == 1000ms == 1000,000us）
function:回调函数
data:给回调函数传的参数

返回值：定时器的id号。

e.g.:
guint timer = g_timeout_add(500,(GSourceFunc)deal_time,NULL);
每隔500毫秒执行一次,deal_time()回调函数。

注意：

当回调函数，返回值为false时，定时器执行一次便会停止工作。不再循环执行。
所以，要想定时器连续工作，循环执行所指定的回调函数，应该返回TRUE.


2) 定时器的销毁

gboolean g_source_remove(guint tag);

tag:定时器id号

返回值：TRUE代表成功，FALSE代表失败



*/


guint timer; //定时器

// 声明回调函数on_delete_event
void on_delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)
{
  gtk_main_quit();// 还是需要调用系统的。
}


/*
 *功能：设置控件字体大小
widget: 需要改变字体的控件
size: 字体大小
is_button: TRUE代表控件为按钮，FALSE为其他控件

*/

void
set_widget_font_size(GtkWidget *widget,int size,int is_button)
{
  GtkWidget *labelChild;
  PangoFontDescription *font;
  gint fontSize = size;


   font = pango_font_description_from_string("Sans");//字体名
   pango_font_description_set_size(font,fontSize*PANGO_SCALE);// 设置字体大小

   if(is_button){
        labelChild = gtk_bin_get_child(GTK_BIN(widget));
   }else{
       labelChild = widget;
   }


   // 设置label字体
   gtk_widget_modify_font(GTK_WIDGET(labelChild),font);

    pango_font_description_free(font);
}


/*
 * 定时器处理函数
 * label：主要用于显示数字
 */

gboolean deal_time(gpointer *label)
{
    char buf[5] = "";
    static int num = 10;
    num--;
    sprintf(buf,"%d",num);
    gtk_label_set_text(GTK_LABEL(label),buf);


    if(0 == num){
         num = 11;
         // g_source_remove(timer);//移除定时器
    }
    return TRUE;// 尽量返回TRUE
}



int
main(int argc,char *argv[])
{
    GtkWidget *window;

    gtk_init(&argc,&argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	// 信号回调函数
    g_signal_connect(G_OBJECT(window),"delete_event"
           ,G_CALLBACK(on_delete_event),NULL);

    gtk_window_set_title(GTK_WINDOW(window),"定时器使用");
    gtk_window_set_default_size(GTK_WINDOW(window),500,100);
    gtk_window_set_position(GTK_WINDOW(window),
    GTK_WIN_POS_CENTER
        );


     gtk_container_set_border_width(GTK_CONTAINER(window),0);

   GtkWidget * label = gtk_label_new("10");

   // gtk_widget_set_size_request(label,38,15);

   set_widget_font_size(label,230,FALSE);
    gtk_container_add(GTK_CONTAINER(window),label);


    timer = g_timeout_add(1000,(GSourceFunc)deal_time,(gpointer)label);

    gtk_widget_show(label);
    gtk_widget_show(window);// 显示控件。参数是要显示的控件的指针。



	// 事件循环。
    gtk_main();

    return EXIT_SUCCESS;
}









