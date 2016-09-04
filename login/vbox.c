#include<gtk/gtk.h>
#include<stdlib.h>



GtkWidget *window;
GtkWidget *vbox;// 和ios相比，是多出来的，ios没有这种界面布局控件。
GtkWidget *table;
GtkWidget *entry;
GtkWidget *button;
GtkWidget *label;

char text[50];
char text1[50];
char a[50];
int i = 0;


void
on_clicked(GtkWidget *widget,gpointer data)
{
	i++;
	gcvt((float)i,3,text);///
	strcat(text,":");
	// 获取文本框的内容，并将其复制到text1字符数组中
	strcpy(text1,gtk_entry_get_text(GTK_ENTRY(entry)));
	strcat(text,text1);
	strcat(a,"\n");
	strcat(a,text);
	gtk_label_set_text(GTK_LABEL(label),a);
}



/*

头文件：#include <stdlib.h>
gcvt(): 将浮点型数转换为字符串(四舍五入)

定义函数：char *gcvt(double number, size_t ndigits, char *buf);
函数说明：gcvt()用来将参数number 转换成ASCII 码字符串，参数ndigits 表示显示的位数。
gcvt()与ecvt()和fcvt()不同的地方在于，
gcvt()所转换后的字符串包含小数点或正负符号。

若转换成功，转换后的字符串会放在参数buf 指针所指的空间。

返回值：返回一字符串指针，此地址即为buf 指针。



#if (defined __USE_XOPEN_EXTENDED && !defined __USE_XOPEN2K8) \
    || defined __USE_SVID
 Convert floating point numbers to strings.  The returned values are
   valid only until another call to the same function.  

 Convert VALUE to a string with NDIGIT digits and return a pointer to
   this.  Set *DECPT with the position of the decimal character and *SIGN
   with the sign of the number.  

extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
		   int *__restrict __sign) __THROW __nonnull ((3, 4)) __wur;

 Convert VALUE to a string rounded to NDIGIT decimal digits.  Set *DECPT
   with the position of the decimal character and *SIGN with the sign of
   the number. 

extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
		   int *__restrict __sign) __THROW __nonnull ((3, 4)) __wur;

 If possible convert VALUE to a string with NDIGIT significant digits.
   Otherwise use exponential representation.  The resulting string will
   be written to BUF.  

extern char *gcvt (double __value, int __ndigit, char *__buf)
     __THROW __nonnull ((3)) __wur;

#endif

*/



int 
main(int argc,char *argv[])
{

	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("我的评论",-1,NULL,NULL,NULL)
						);
	// g_locale_to_utf8()支持中文字符显示。
	gtk_container_border_width(GTK_CONTAINER(window),5);


	// 框
	vbox = gtk_vbox_new(FALSE,10);


	// 标签
	label = gtk_label_new(
			g_locale_to_utf8("评论内容",-1,NULL,NULL,NULL));

	table= gtk_table_new(2,2,FALSE);


	// 文本框
	entry = gtk_entry_new();


	// 按钮
	button = gtk_button_new_with_label(
				g_locale_to_utf8("发表评论",-1,NULL,NULL,NULL));


	
	gtk_container_add(GTK_CONTAINER(window),vbox);

	gtk_box_pack_start(GTK_BOX(vbox),label,TRUE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(vbox),table,TRUE,FALSE,5);


	
	gtk_table_attach(GTK_TABLE(table),entry,0,2,0,1,
				(GtkAttachOptions)(GTK_EXPAND),(GtkAttachOptions)(0),5,5);

	gtk_table_attach(GTK_TABLE(table),button,1,2,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),0,0);


	// 显示窗口中的所有元件
	gtk_widget_show_all(window);


	//为提交按钮添加回调函数
    g_signal_connect(G_OBJECT(button),"clicked"
            ,G_CALLBACK(on_clicked),window);
	
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

