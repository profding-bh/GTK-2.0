#include<gtk/gtk.h>
// 这是每个gtk+2.0 程序都要包含的头文件。
#include<stdlib.h>
#include<stdio.h>


GtkWidget *window;
GtkWidget * label;

// 在子线程中如果更新UI
/*

要在GTK的线程更新ui，则需要调用
gdk_threads_enter();
// UI控件更新。
gdk_threads_leave();



// to-do:

gdk_threads_*()的作用并不是进入线程，据网上说是线程同步用的。
但一定要将要更新的部位包裹住，有多少个地方需要更新界面，就用多少次gdk_threads_*()，将其包裹住

e.g.:

void  Thread(){
……
gdk_threads_enter();
gtk_label_set_text(GTK_LABEL(label),"hello1.");
gdk_threads_leave();
……
gdk_threads_enter();
gtk_label_set_text(GTK_LABEL(label),"hello2.");
gdk_threads_leave();
……
gdk_threads_enter();
gtk_label_set_text(GTK_LABEL(label),"hello2.");
gdk_threads_leave();
……
}

*/

// 多线程必须加gthread-2.0库 
// $(CC) -o  thread thread.c `pkg-config --cflags --libs gtk+-2.0 gthread-2.0` -std=gnu99 




// 声明回调函数on_delete_event
void on_delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)
{
   gtk_main_quit();// 还是需要调用系统的。
}

void hello(){

   int i;
   for(i = 10;;i--){

	// 使用gdk_threads_*()括起 将要刷新的页面

	char buf[6];
	sprintf(buf,"%d",i);
	sleep(1);//1s-->也可以这样，实现倒计时
	gdk_threads_enter();
	gtk_label_set_text(GTK_LABEL(label),buf);
	gdk_threads_leave();
	if(0 == i) 
		i = 11;
	}
}



int
main(int argc,char *argv[])
{
    
    //gtk_init(&argc,&argv);
    gtk_init(NULL,NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	// 信号回调函数
    g_signal_connect(G_OBJECT(window),"delete_event"
           ,G_CALLBACK(on_delete_event),NULL);

    gtk_window_set_title(GTK_WINDOW(window),"多线程使用");

  //  gtk_window_set_default_size(GTK_WINDOW(window),500,100);

  gtk_widget_set_usize(GTK_WIDGET(window),500,100);

    gtk_window_set_position(GTK_WINDOW(window),
    GTK_WIN_POS_CENTER
        );



    gtk_container_set_border_width(GTK_CONTAINER(window),0);


    label = gtk_label_new("10");
   
    gtk_container_add(GTK_CONTAINER(window),label);
   
    gtk_widget_show(label);
    gtk_widget_show(window);// 显示控件。参数是要显示的控件的指针。


// 线程的初始化
 if(!g_thread_supported()) 
     g_thread_init(NULL);
gdk_threads_init();


// 创建线程
// g_thread_create((GThreadFunc)hello,NULL,FALSE,NULL);
g_thread_new("子线程",(GThreadFunc)hello,NULL);

// 事件循环。
gdk_threads_enter();
    gtk_main();
gdk_threads_leave();

    return EXIT_SUCCESS;
}









