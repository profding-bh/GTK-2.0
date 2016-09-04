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

	GtkWidget *vbox;// 和ios相比，是多出来的，ios没有这种界面布局控件。


	GtkWidget *label1;
	GtkWidget *label2;
	GtkWidget *label3;

	GtkObject *adjustment;
	GtkWidget *bar;
	GtkWidget *spinbutton;

	GList *glist;

	GtkWidget *combo;

	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("控制元件",-1,NULL,NULL,NULL)
						);
	// g_locale_to_utf8()支持中文字符显示。
	
	gtk_container_border_width(GTK_CONTAINER(window),40);

	vbox = gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(window),vbox);


/*
和ios相比，可以省掉设置x,y,width,height这么恶心的事

*/

	// 标签
	label1 = gtk_label_new(
			g_locale_to_utf8("进度条：",-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(vbox),label1,TRUE,TRUE,0);



	// 进度条
	adjustment=gtk_adjustment_new(70.0,0.0,100.0,1.0,0.0,0.0);
	
	bar = gtk_progress_bar_new_with_adjustment(GTK_ADJUSTMENT(adjustment));
	
	
	gtk_progress_bar_set_bar_style(GTK_PROGRESS_BAR(bar),
	GTK_PROGRESS_CONTINUOUS);

	gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(bar),
	GTK_PROGRESS_LEFT_TO_RIGHT);

	gtk_box_pack_start(GTK_BOX(vbox),bar,TRUE,TRUE,15);	


/*
void       gtk_progress_bar_set_orientation      (GtkProgressBar *pbar,
						  GtkProgressBarOrientation orientation);


void       gtk_progress_bar_set_bar_style        (GtkProgressBar *pbar,
						  GtkProgressBarStyle style);

simple interface 

void       gtk_combo_set_popdown_strings   (GtkCombo*    combo, 
                                            GList        *strings);


*/

	
	label2 = gtk_label_new(
			g_locale_to_utf8("微调按钮：",-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(vbox),label2,TRUE,TRUE,0);	


	// 微调按钮
	adjustment = gtk_adjustment_new(80.0,0.0,100.0,1.0,0.0,0.0);
   	spinbutton = gtk_spin_button_new(
	GTK_ADJUSTMENT(adjustment),1.0,1
	);
	
	gtk_box_pack_start(GTK_BOX(vbox),spinbutton,TRUE,TRUE,0);	
	
	
	//组合框
	label3 = gtk_label_new(
			g_locale_to_utf8("下拉列表：",-1,NULL,NULL,NULL));

	gtk_box_pack_start(GTK_BOX(vbox),label3,TRUE,TRUE,0);
	
	glist=NULL;
	glist = g_list_append(glist,"banana");
	glist = g_list_append(glist,"apple");
	glist = g_list_append(glist,"orange");
	glist = g_list_append(glist,"pear");//梨
	glist = g_list_append(glist,"strawberry");
	
	combo=gtk_combo_new();
	
	gtk_combo_set_popdown_strings(GTK_COMBO(combo),glist);

	gtk_box_pack_start(GTK_BOX(vbox),combo,TRUE,TRUE,15);	





	// 显示窗口中的所有元件
	gtk_widget_show_all(window);

	//退出-->信号事件处理必须放在主循环之前。
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

