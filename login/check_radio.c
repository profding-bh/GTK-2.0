#include<gtk/gtk.h>
#include<stdio.h>


int 
main(int argc,char *argv[])
{
	GtkWidget *window;
	GtkWidget *table;// 和ios相比，是多出来的，ios没有这种界面布局控件。

	GtkWidget *label1;
	GtkWidget *label2;

	GSList *group;
	
	GtkWidget *check;
	GtkWidget *radio;
	gtk_init(&argc,&argv);// 初始化图形显示环境。
	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("单选、复选按钮",-1,NULL,NULL,NULL)
						);
	// g_locale_to_utf8()支持中文字符显示。
	
	gtk_container_border_width(GTK_CONTAINER(window),15);

	table = gtk_table_new(4,4,FALSE);
	gtk_container_add(GTK_CONTAINER(window),table);

	
	// 标签
	label1 = gtk_label_new(
			g_locale_to_utf8("业余时间活动爱好：",-1,NULL,NULL,NULL));
	label2 = gtk_label_new(
			g_locale_to_utf8("平均每天学习时间：",-1,NULL,NULL,NULL));

	// 添加到表格
	gtk_table_attach(GTK_TABLE(table),label1,0,2,0,1,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),0,0);

	gtk_table_attach(GTK_TABLE(table),label2,0,2,2,3,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),0,5);


	// 4个复选按钮
	check = gtk_check_button_new_with_label(
	g_locale_to_utf8("足球",-1,NULL,NULL,NULL));

	gtk_table_attach(GTK_TABLE(table),check,0,1,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,10);

	check = gtk_check_button_new_with_label(
	g_locale_to_utf8("篮球",-1,NULL,NULL,NULL));

	gtk_table_attach(GTK_TABLE(table),check,1,2,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,10);



	check = gtk_check_button_new_with_label(
	g_locale_to_utf8("爬山",-1,NULL,NULL,NULL));

	gtk_table_attach(GTK_TABLE(table),check,2,3,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,10);

	check = gtk_check_button_new_with_label(
	g_locale_to_utf8("郊游",-1,NULL,NULL,NULL));

	gtk_table_attach(GTK_TABLE(table),check,3,4,1,2,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,10);


	// 4个单选按钮
	// 注意：生成第一个ratio按钮时，group参数为NULL,而后，
	// 每次在该组中创建一个ratio按钮都要使用gtk_radio_button_group()函数
	// 获取新的group值。
	radio = gtk_radio_button_new_with_label(NULL,
	g_locale_to_utf8("3-4小时",-1,NULL,NULL,NULL));

	gtk_table_attach(GTK_TABLE(table),radio,0,1,3,4,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);

	group= gtk_radio_button_group(GTK_RADIO_BUTTON(radio));
	
	radio = gtk_radio_button_new_with_label(group,
	g_locale_to_utf8("4-5小时",-1,NULL,NULL,NULL));

	gtk_table_attach(GTK_TABLE(table),radio,1,2,3,4,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);

	group= gtk_radio_button_group(GTK_RADIO_BUTTON(radio));
	radio = gtk_radio_button_new_with_label(group,
	g_locale_to_utf8("5-6小时",-1,NULL,NULL,NULL));

	gtk_table_attach(GTK_TABLE(table),radio,2,3,3,4,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);

	group= gtk_radio_button_group(GTK_RADIO_BUTTON(radio));
	radio = gtk_radio_button_new_with_label(group,
	g_locale_to_utf8("6小时以上",-1,NULL,NULL,NULL));

	gtk_table_attach(GTK_TABLE(table),radio,3,4,3,4,
				(GtkAttachOptions)(0),(GtkAttachOptions)(0),5,5);


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

Signals — A means for customization of object behaviour 
and a general purpose notification mechanism



g_signal_connect()
在点击“提交”按钮时，产生来相应的信号。
系统自动调用相应的信号处理函数。 

#define      g_signal_connect(instance, detailed_signal, c_handler, data)

Connects a GCallback function to a signal for a particular object.
The handler will be called before the default handler of the signal.
See memory management of signal handlers for details on how to handle the
 return value and memory management of data .

Parameters:
	
instance
the instance to connect to.
 
detailed_signal
a string of the form "signal-name::detail".
 
c_handler
the GCallback to connect.
 
data
data to pass to c_handler calls.

Returns:

the handler id (always greater than 0 for successful connections)




gchar *
g_locale_to_utf8 (const gchar *opsysstring,
                  gssize len,
                  gsize *bytes_read,
                  gsize *bytes_written,
                  GError **error);

Converts a string 
which is in the encoding used for strings by the C runtime
 (usually the same as that used by the operating system)
 in the current locale into a UTF-8 string.
 
Parameters:

opsysstring  a string in the encoding of the current locale. 
On Windows this means the system codepage.

len
the length of the string, or -1 if the string is nul-terminated
 (Note that some encodings may allow nul bytes to occur inside strings. 
In that case, using -1 for the len parameter is unsafe)

bytes_read
location to store the number of bytes in the input string 
that were successfully converted, or NULL. 
Even if the conversion was successful, 
this may be less than len if there were partial 
characters at the end of the input. 
If the error G_CONVERT_ERROR_ILLEGAL_SEQUENCE occurs, 
the value stored will the byte offset after the last valid input sequence.

bytes_written
the number of bytes stored in the output buffer 
(not including the terminating nul).

error
location to store the error occurring, or NULL to ignore errors. 
Any of the errors in GConvertError may occur.


Returns：
A newly-allocated buffer containing the converted string, 
or NULL on an error, and error will be set.




gtk_radio_button_group

#define gtk_radio_button_group gtk_radio_button_get_group



gtk_radio_button_group is deprecated 
and should not be used in newly-written code.
Deprecated compatibility macro.
 Use gtk_radio_button_get_group() instead.


GSList *
gtk_radio_button_get_group (GtkRadioButton *radio_button);


Retrieves the group assigned to a radio button.

Parameters:
radio_button  a GtkRadioButton.

Returns：
a linked list containing all the radio buttons 
in the same group as radio_button . 
The returned list is owned by the radio 
button and must not be modified or freed.









*/

