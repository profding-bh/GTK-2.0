#include<gtk/gtk.h>
// 这是每个gtk+2.0 程序都要包含的头文件。
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>


#define handle_error_en(en,msg)\
    do{errno = en; perror(msg);exit(EXIT_FAILURE);} while(0)


static int done = 0;
static int cleanup_pop_arg = 0;
static int cnt = 0;


gchar timestr[20] = "5"; // 倒计时的字符串。
gint count = 1;
GtkLabel *label;



// 声明回调函数on_delete_event
void on_delete_event(GtkWidget *widget,GdkEvent *event,gpointer data)
{
  gtk_main_quit();// 还是需要调用系统的。
}



// 整数转换成字符串

void itoa (int n,char s[])
{
int i,j,sign;
int m,p;
if((sign=n)<0)//记录符号
n=-n;//使n成为正数
i=0;
do{
       s[i++]=n%10+'0';//取下一个数字
}
while ((n/=10)>0);//删除该数字
if(sign<0)
s[i++]='-';
s[i]='\0';

/*
for(j=i;j>=0;j--)//生成的数字是逆序的，所以要逆序输出
       printf("%c",s[j]);
printf("\n");
*/
for(m=0,p = i-1; m< p;m++,p--)//逆序
   {
int a = s[m];
s[m] = s[p];
s[p] = a;
}
}


static void
cleanup_handler(void *arg)
{
     printf("Called clean-up handler\n");
     cnt  = 0;// cnt 被清 0
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



static void *
thread_start_2(void *arg)
{
    time_t curr;
	int n;
    printf("New thread started\n");

    pthread_cleanup_push(cleanup_handler,NULL);


    curr = time(NULL);
    while(!done){
       
          sleep(1);
            n = atoi(timestr);// 还是有问题。
	        n--;
           itoa(n,timestr);
          gdk_threads_enter();
          gtk_label_set_text(label,timestr);// 可以认为是主线程刷新UI
          gdk_threads_leave();
        
    }
    pthread_cleanup_pop(cleanup_pop_arg);// pthread_cleanup_pop(0)将不会调用cleanup_handler
    printf("xxxxxxx\n");
    return NULL;
}




static void *
thread_start(void *arg)
{
    time_t curr;
	int n;
    printf("New thread started\n");

    pthread_cleanup_push(cleanup_handler,NULL);


    curr = time(NULL);
    while(!done){
         //pthread_testcancel(); /* A cancellation point*/
         if(curr < time(NULL)){// 每隔1s，程序不稳定啊
             curr = time(NULL);
            n = atoi(timestr);
	     n--;
           itoa(n,timestr);
          gdk_threads_enter();
          gtk_label_set_text(label,timestr);// 可以认为是主线程刷新UI
          gdk_threads_leave();
         }
    }
    pthread_cleanup_pop(cleanup_pop_arg);// pthread_cleanup_pop(0)将不会调用cleanup_handler
    printf("xxxxxxx\n");
    return NULL;
}



int
main(int argc,char *argv[])
{
    GtkWidget *window;
    pthread_t thr;
    int s;
    void *res;

    gtk_init(&argc,&argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	// 信号回调函数
    g_signal_connect(G_OBJECT(window),"delete_event"
            ,G_CALLBACK(on_delete_event),NULL);

    gtk_window_set_title(GTK_WINDOW(window),"Hello 功能实现");
    gtk_window_set_default_size(GTK_WINDOW(window),500,100);
    gtk_window_set_position(GTK_WINDOW(window),
    GTK_WIN_POS_CENTER_ON_PARENT
        );


     gtk_container_set_border_width(GTK_CONTAINER(window),40);


    label = gtk_label_new(timestr);

  //  gtk_widget_set_size_request(label,38,15);

    gtk_container_add(GTK_CONTAINER(window),label);

    gtk_widget_show((GtkWidget*)label);
    gtk_widget_show(window);// 显示控件。参数是要显示的控件的指针。



    //创建一个子线程。
    s = pthread_create(&thr,NULL,thread_start_2,NULL);
    if(0 != s)
        handle_error_en(s,"pthread_create");

	// 事件循环。
    gtk_main();

    return EXIT_SUCCESS;
}









