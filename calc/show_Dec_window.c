#include<gtk/gtk.h>

void
show_Dec_window()
{
	gtk_button_set_label(GTK_BUTTON(button1),"pi");// 按钮pi需要显示
	gtk_widget_show(button1);
	gtk_button_set_label(GTK_BUTTON(button2),"sin");
	gtk_widget_show(button2);// 按钮sin需要显示
	
	
	gtk_button_set_label(GTK_BUTTON(button3),"cos");// 按钮cos需要显示
	gtk_widget_show(button3);
	gtk_button_set_label(GTK_BUTTON(button4),"tan");
	gtk_widget_show(button4);// 按钮tan需要显示

	gtk_button_set_label(GTK_BUTTON(button6),"Exp");// 按钮Exp需要显示
	gtk_widget_show(button6);
	gtk_button_set_label(GTK_BUTTON(button14),"7");
	gtk_widget_show(button14);// 数字按钮7需要显示

	gtk_button_set_label(GTK_BUTTON(button15),"4");
	gtk_widget_show(button15);// 数字按钮4需要显示
	gtk_button_set_label(GTK_BUTTON(button18),"");
	gtk_widget_show(button18);// 数字按钮A显示为空

	gtk_button_set_label(GTK_BUTTON(button19),"8");
	gtk_widget_show(button19);// 数字按钮8需要显示
	gtk_button_set_label(GTK_BUTTON(button20),"5");
	gtk_widget_show(button20);// 数字按钮5需要显示

	gtk_button_set_label(GTK_BUTTON(button21),"2");
	gtk_widget_show(button21);// 数字按钮2需要显示
	gtk_button_set_label(GTK_BUTTON(button23),"");
	gtk_widget_show(button23);// 数字按钮B显示为空

	gtk_button_set_label(GTK_BUTTON(button24),"9");
	gtk_widget_show(button24);// 数字按钮9需要显示
	gtk_button_set_label(GTK_BUTTON(button25),"6");
	gtk_widget_show(button25);// 数字按钮6需要显示

	

	gtk_button_set_label(GTK_BUTTON(button26),"3");
	gtk_widget_show(button26);// 数字按钮3需要显示
	gtk_button_set_label(GTK_BUTTON(button28),"");
	gtk_widget_show(button28);// 数字按钮C显示为空

	
	gtk_button_set_label(GTK_BUTTON(button33),"");
	gtk_widget_show(button33);// 数字按钮D显示为空
	gtk_button_set_label(GTK_BUTTON(button38),"");
	gtk_widget_show(button38);// 数字按钮E显示为空


	gtk_button_set_label(GTK_BUTTON(button42),"");
	gtk_widget_show(button42);	// 数字按钮F显示为空
}
