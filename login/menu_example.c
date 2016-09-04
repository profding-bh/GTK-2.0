#include<gtk/gtk.h>
#include<stdio.h>



int 
main(int argc,char *argv[])
{

	
	GtkWidget *window;

	GtkWidget *menu;//
	GtkWidget *menubar;
	GtkWidget *rootmenu;
	GtkWidget *menuitem;

	gtk_init(&argc,&argv);// 初始化图形显示环境。

	// 窗口
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),
						g_locale_to_utf8("下拉菜单",-1,NULL,NULL,NULL)
						);
	gtk_widget_set_usize(window,200,40);

	// 创建菜单条
	menubar = gtk_menu_bar_new();

	// 菜单条加入到窗口中
	gtk_container_add(GTK_CONTAINER(window),menubar);


	// 创建一个新菜单
	menu = gtk_menu_new();
		
	menuitem = gtk_menu_item_new_with_label(
	g_locale_to_utf8("新建",-1,NULL,NULL,NULL));
	gtk_menu_append(GTK_MENU(menu),menuitem);

	menuitem = gtk_menu_item_new_with_label(
	g_locale_to_utf8("打开",-1,NULL,NULL,NULL));
	gtk_menu_append(GTK_MENU(menu),menuitem);

	menuitem = gtk_menu_item_new_with_label(
	g_locale_to_utf8("关闭",-1,NULL,NULL,NULL));
	gtk_menu_append(GTK_MENU(menu),menuitem);

	menuitem = gtk_menu_item_new_with_label(
	g_locale_to_utf8("保存",-1,NULL,NULL,NULL));
	gtk_menu_append(GTK_MENU(menu),menuitem);

	// 主菜单
	rootmenu = gtk_menu_item_new_with_label(
	g_locale_to_utf8("文件",-1,NULL,NULL,NULL));
	// menu作为rootmenu的子菜单
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),menu);
	// rootmenu作为menubar的一项
	gtk_menu_bar_append(GTK_MENU_BAR(menubar),rootmenu);



	// 创建另一个新菜单
	menu = gtk_menu_new();

	menuitem = gtk_menu_item_new_with_label(
	g_locale_to_utf8("复制",-1,NULL,NULL,NULL));
	gtk_menu_append(GTK_MENU(menu),menuitem);

	menuitem = gtk_menu_item_new_with_label(
	g_locale_to_utf8("剪切",-1,NULL,NULL,NULL));
	gtk_menu_append(GTK_MENU(menu),menuitem);

	menuitem = gtk_menu_item_new_with_label(
	g_locale_to_utf8("粘贴",-1,NULL,NULL,NULL));
	gtk_menu_append(GTK_MENU(menu),menuitem);

	menuitem = gtk_menu_item_new_with_label(
	g_locale_to_utf8("删除",-1,NULL,NULL,NULL));
	gtk_menu_append(GTK_MENU(menu),menuitem);

	// 主菜单
	rootmenu = gtk_menu_item_new_with_label(
	g_locale_to_utf8("编辑",-1,NULL,NULL,NULL));
	
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(rootmenu),menu);
	
	gtk_menu_bar_append(GTK_MENU_BAR(menubar),rootmenu);


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

