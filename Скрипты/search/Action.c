Action()
{
	
	lr_start_transaction("search");
	
	lr_start_transaction("web_tours_goto_welcome");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_find("Fail=NotFound",
		"Text=To make reservations,please enter your account information to the left.",
		LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("web_tours_goto_welcome", LR_AUTO);
	
	lr_start_transaction("web_tours_login");


	web_add_header("Origin", 
		"http://localhost:1080");
	
	web_reg_find("Fail=NotFound",
	"Text=User password was correct",
		LAST);

	web_submit_form("login.pl", 
		"Snapshot=t15.inf", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		LAST);
	
	lr_end_transaction("web_tours_login", LR_AUTO);
	
	lr_start_transaction("web_tours_search");


	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t16.inf", 
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_reg_find("Fail=NotFound",
		"Text=Flight Selections",
		LAST);

	web_submit_form("reservations.pl", 
		"Snapshot=t17.inf", 
		ITEMDATA, 
		"Name=depart", "Value={depCity}", ENDITEM, 
		"Name=departDate", "Value={depDate}", ENDITEM, 
		"Name=arrive", "Value={arCity}", ENDITEM, 
		"Name=returnDate", "Value={arDate}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value={sitPref}", ENDITEM, 
		"Name=seatType", "Value={sitType}", ENDITEM, 
		LAST);
	
	lr_end_transaction("web_tours_search",LR_AUTO);
	
	lr_start_transaction("web_tours_logout");
	
	web_reg_find("Fail=NotFound",
		"Text=Welcome to the Web Tours site",
		LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t18.inf", 
		LAST);
	
	lr_end_transaction("web_tours_logout", LR_AUTO);

	
	lr_end_transaction("search", LR_AUTO);


	return 0;
}