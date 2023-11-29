Action()
{
	
	lr_start_transaction("signIn");

	lr_start_transaction("web_tours_goto_welcome");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_find("Fail=NotFound",
		"Text=To make reservations,please enter your account information to the left.",
		LAST);
	
	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("web_tours_goto_welcome", LR_AUTO);

	lr_start_transaction("web_tours_gotoSignUp");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_reg_find("Fail=NotFound",
		"Text=User Information",
		LAST);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("web_tours_gotoSignUp",LR_AUTO);

	lr_start_transaction("web_tours_registration");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Upgrade-Insecure-Requests", 
		"1"); 

	web_reg_find("Fail=NotFound",
		"Text=for registering and welcome to the Web Tours family.",
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={randParLogin}", ENDITEM, 
		"Name=password", "Value={randParLogin}", ENDITEM, 
		"Name=passwordConfirm", "Value={randParLogin}", ENDITEM, 
		"Name=firstName", "Value={randParName}", ENDITEM, 
		"Name=lastName", "Value={randParName}", ENDITEM, 
		"Name=address1", "Value={randParAddress}", ENDITEM, 
		"Name=address2", "Value={randParAddress}", ENDITEM, 
		"Name=register.x", "Value=65", ENDITEM, 
		"Name=register.y", "Value=15", ENDITEM, 
		LAST);
	
	lr_end_transaction("web_tours_registration",LR_AUTO);
	
	lr_start_transaction("web_tours_registration_continue");
	
	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_image("button_next.gif", 
		"Src=/WebTours/images/button_next.gif", 
		"Snapshot=t7.inf", 
		LAST);
	
	lr_end_transaction("web_tours_registration_continue", LR_AUTO);

	lr_end_transaction("signIn", LR_AUTO);

	return 0;
}