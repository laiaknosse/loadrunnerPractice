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
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_submit_form("login.pl", 
		"Snapshot=t21.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t22.inf", 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t23.inf", 
		LAST);

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_submit_form("reservations.pl", 
		"Snapshot=t24.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=11/18/2023", ENDITEM, 
		"Name=arrive", "Value=London", ENDITEM, 
		"Name=returnDate", "Value=11/19/2023", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t25.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=020;338;11/18/2023", ENDITEM, 
		"Name=reserveFlights.x", "Value=54", ENDITEM, 
		"Name=reserveFlights.y", "Value=14", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_submit_form("reservations.pl_3", 
		"Snapshot=t26.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value= asdasd", ENDITEM, 
		"Name=address2", "Value=asdasd", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=123123", ENDITEM, 
		"Name=expDate", "Value=10/29", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		LAST);

	lr_think_time(4);

	web_image("Itinerary Button_2", 
		"Alt=Itinerary Button", 
		"Snapshot=t27.inf", 
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(4);

	web_submit_form("itinerary.pl", 
		"Snapshot=t28.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		LAST);

	return 0;
}