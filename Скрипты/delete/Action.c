Action()
{
	lr_start_transaction("delete");
	
	lr_start_transaction("web_tours_goto_welcome");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

/*Correlation comment - Do not change!  Original value='137696.739489672HAicHHzpADHftctQzpzfzccf' Name ='userSession' Type ='Manual'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
	
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
	
	lr_start_transaction("web_tours_login");

	web_add_header("Origin", 
		"http://localhost:1080");
			
	web_reg_find("Fail=NotFound",
	"Text=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value=jojo", ENDITEM,
		"Name=password", "Value=bean", ENDITEM,
		"Name=login.x", "Value=55", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("web_tours_login",LR_AUTO);

	lr_start_transaction("web_tours_goto_itinerary");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_save_param("outboundFlight",
		"LB=name=\"flightID\" value=\"",
		"RB=\"",
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("web_tours_goto_itinerary",LR_AUTO);
	
	lr_start_transaction("web_tours_deleteSelected");

	web_add_header("Origin", 
		"http://localhost:1080");
	
	web_submit_form("itinerary.pl", 
		"Snapshot=t44.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=47", ENDITEM, 
		"Name=removeFlights.y", "Value=12", ENDITEM,		
		LAST);
	
	web_reg_find("Fail=Found",
		"Text={outboundFlight}",
		LAST);

	lr_end_transaction("web_tours_deleteSelected",LR_AUTO);

	lr_start_transaction("web_tours_logout");
	
	web_reg_find("Fail=NotFound",
		"Text=Welcome to the Web Tours site",
		LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("web_tours_logout",LR_AUTO);
	
	lr_end_transaction("delete", LR_AUTO);


	return 0;
}