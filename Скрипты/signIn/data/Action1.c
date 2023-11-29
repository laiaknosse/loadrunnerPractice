Action1()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_url("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_submit_form("login.pl_2", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=username", "Value=asdf", ENDITEM, 
		"Name=password", "Value=asdf", ENDITEM, 
		"Name=passwordConfirm", "Value=asdf", ENDITEM, 
		"Name=firstName", "Value=asdf", ENDITEM, 
		"Name=lastName", "Value=asdf", ENDITEM, 
		"Name=address1", "Value=asdf", ENDITEM, 
		"Name=address2", "Value=asdf", ENDITEM, 
		"Name=register.x", "Value=41", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t7.inf", 
		LAST);

	return 0;
}