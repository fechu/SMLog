#SMLog
SMLogger ist eine klasse die das Logging auf iOS Geräten vereinfacht. Es ist möglich Nachrichten mit verschiedenen Leveln zu Loggen. Es ist konfigurierbar welche Level gelogt werden sollen. 

##Anwendung
Es kann auf 2 verschiedenen Wegen gelogt werden. Entweder mit der Klasse `SMLogger`oder über die Makros. 

###SMLogger 

Die Anwendung wurde so einfach wie möglich gemacht. Beispiel:

    [SMLogger logDebug:@"Ölstand: %f", oelstand];

Das Resultat sieht dann so aus: 

	DEBUG	Ölstand: 0.756
	
###Makros
Falls die Klasse immernoch zu kompliziert ist, können die Makros verwendet werden. Beispiel:

	DLog(LEVEL_DEBUG, @"Ölstand: %f", oelstand);
	
Das Resultat sieht dann so aus: 

	[DEBUG]   Ölstand: 0.756
	
Zusätzlich zu all den Levels kann mit den Makros UILog verwendet werden. Dieses Makro zeigt den Text in einer UIAlertView an.