Action1()
{
//
//	web_set_sockets_option("SSL_VERSION", "AUTO");
//
//	web_add_auto_header("Upgrade-Insecure-Requests", 
//		"1");
//
//	web_url("welcome.pl", 
//		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=http://localhost:1080/WebTours/", 
//		"Snapshot=t8.inf", 
//		"Mode=HTML", 
//		LAST);
//
//	web_revert_auto_header("Upgrade-Insecure-Requests");
//
//	web_add_header("Origin", 
//		"http://localhost:1080");
//
//	lr_think_time(10);
//
//	web_submit_form("login.pl", 
//		"Snapshot=t9.inf", 
//		ITEMDATA, 
//		"Name=username", "Value=jojo", ENDITEM, 
//		"Name=password", "Value=bean", ENDITEM, 
//		LAST);
//
//	web_add_auto_header("Upgrade-Insecure-Requests", 
//		"1");
//
//	web_image("Search Flights Button", 
//		"Alt=Search Flights Button", 
//		"Snapshot=t10.inf", 
//		LAST);
//
//	web_add_auto_header("Origin", 
//		"http://localhost:1080");
//
//	web_submit_form("reservations.pl", 
//		"Snapshot=t11.inf", 
//		ITEMDATA, 
//		"Name=depart", "Value=Denver", ENDITEM, 
//		"Name=departDate", "Value=11/30/2023", ENDITEM, 
//		"Name=arrive", "Value=Paris", ENDITEM, 
//		"Name=returnDate", "Value=12/01/2023", ENDITEM, 
//		"Name=numPassengers", "Value=3", ENDITEM, 
//		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
//		"Name=seatPref", "Value=None", ENDITEM, 
//		"Name=seatType", "Value=Coach", ENDITEM, 
//		LAST);
//
//	web_submit_form("reservations.pl_2", 
//		"Snapshot=t12.inf", 
//		ITEMDATA, 
//		"Name=outboundFlight", "Value=042;331;11/30/2023", ENDITEM, 
//		"Name=reserveFlights.x", "Value=34", ENDITEM, 
//		"Name=reserveFlights.y", "Value=10", ENDITEM, 
//		LAST);
//
//	web_submit_form("reservations.pl_3", 
//		"Snapshot=t13.inf", 
//		ITEMDATA, 
//		"Name=firstName", "Value=Jojo", ENDITEM, 
//		"Name=lastName", "Value=Bean", ENDITEM, 
//		"Name=address1", "Value=asdf", ENDITEM, 
//		"Name=address2", "Value=asdf", ENDITEM, 
//		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
//		"Name=pass2", "Value=asdf", ENDITEM, 
//		"Name=pass3", "Value=asdf", ENDITEM, 
//		"Name=creditCard", "Value=123", ENDITEM, 
//		"Name=expDate", "Value=10/29", ENDITEM, 
//		"Name=saveCC", "Value=<OFF>", ENDITEM, 
//		LAST);
//
//	lr_think_time(4);
//
//	web_submit_form("reservations.pl_4", 
//		"Snapshot=t14.inf", 
//		ITEMDATA, 
//		"Name=Book Another.x", "Value=47", ENDITEM, 
//		"Name=Book Another.y", "Value=9", ENDITEM, 
//		LAST);
//
//	lr_think_time(7);
//
//	web_submit_form("reservations.pl_5", 
//		"Snapshot=t15.inf", 
//		ITEMDATA, 
//		"Name=depart", "Value=Denver", ENDITEM, 
//		"Name=departDate", "Value=11/30/2023", ENDITEM, 
//		"Name=arrive", "Value=Portland", ENDITEM, 
//		"Name=returnDate", "Value=12/01/2023", ENDITEM, 
//		"Name=numPassengers", "Value=2", ENDITEM, 
//		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
//		"Name=seatPref", "Value=None", ENDITEM, 
//		"Name=seatType", "Value=Coach", ENDITEM, 
//		LAST);
//
//	web_submit_form("reservations.pl_6", 
//		"Snapshot=t16.inf", 
//		ITEMDATA, 
//		"Name=outboundFlight", "Value=053;225;11/30/2023", ENDITEM, 
//		"Name=reserveFlights.x", "Value=39", ENDITEM, 
//		"Name=reserveFlights.y", "Value=13", ENDITEM, 
//		LAST);
//
//	lr_think_time(11);
//
//	web_submit_form("reservations.pl_7", 
//		"Snapshot=t17.inf", 
//		ITEMDATA, 
//		"Name=firstName", "Value=Jojo", ENDITEM, 
//		"Name=lastName", "Value=Bean", ENDITEM, 
//		"Name=address1", "Value=asdf", ENDITEM, 
//		"Name=address2", "Value=asdf", ENDITEM, 
//		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
//		"Name=pass2", "Value=asdf", ENDITEM, 
//		"Name=creditCard", "Value=123", ENDITEM, 
//		"Name=expDate", "Value=10/29", ENDITEM, 
//		"Name=saveCC", "Value=<OFF>", ENDITEM, 
//		LAST);
//
//	web_submit_form("reservations.pl_8", 
//		"Snapshot=t18.inf", 
//		ITEMDATA, 
//		"Name=Book Another.x", "Value=83", ENDITEM, 
//		"Name=Book Another.y", "Value=13", ENDITEM, 
//		LAST);
//
//	lr_think_time(5);
//
//	web_submit_form("reservations.pl_9", 
//		"Snapshot=t19.inf", 
//		ITEMDATA, 
//		"Name=depart", "Value=Denver", ENDITEM, 
//		"Name=departDate", "Value=11/30/2023", ENDITEM, 
//		"Name=arrive", "Value=Zurich", ENDITEM, 
//		"Name=returnDate", "Value=12/01/2023", ENDITEM, 
//		"Name=numPassengers", "Value=1", ENDITEM, 
//		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
//		"Name=seatPref", "Value=None", ENDITEM, 
//		"Name=seatType", "Value=Coach", ENDITEM, 
//		LAST);
//
//	web_submit_form("reservations.pl_10", 
//		"Snapshot=t20.inf", 
//		ITEMDATA, 
//		"Name=outboundFlight", "Value=091;375;11/30/2023", ENDITEM, 
//		"Name=reserveFlights.x", "Value=47", ENDITEM, 
//		"Name=reserveFlights.y", "Value=10", ENDITEM, 
//		LAST);
//
//	lr_think_time(6);
//
//	web_submit_form("reservations.pl_11", 
//		"Snapshot=t21.inf", 
//		ITEMDATA, 
//		"Name=firstName", "Value=Jojo", ENDITEM, 
//		"Name=lastName", "Value=Bean", ENDITEM, 
//		"Name=address1", "Value=asdf", ENDITEM, 
//		"Name=address2", "Value=asdf", ENDITEM, 
//		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
//		"Name=creditCard", "Value=123", ENDITEM, 
//		"Name=expDate", "Value=10/29", ENDITEM, 
//		"Name=saveCC", "Value=<OFF>", ENDITEM, 
//		LAST);
//
//	web_revert_auto_header("Origin");
//
//	web_image("Itinerary Button", 
//		"Alt=Itinerary Button", 
//		"Snapshot=t22.inf", 
//		LAST);
//
	return 0;
}