#SMLog
SMLogger ist eine klasse die das Logging auf iOS Geräten vereinfacht. Es ist möglich Nachrichten mit verschiedenen Leveln zu Loggen. Es ist konfigurierbar welche Level gelogt werden sollen. 

##Anwendung
Man kann auf 2 verschiedene wege Log Einträge erstellen. Die eine ist die Klasse SMLogger und die andere sind Makros.

###SMLogger 

Die Anwendung wurde so einfach wie möglich gemacht. Beispiel:

    [SMLogger logDebug:@"Ölstand: %f", oelstand];

Das Resultat sieht dann so aus: 

	DEBUG	Ölstand: 0.756
	
###Makros
Falls die Klasse immernoch zu kompliziert ist, können die Makros verwendet werden. Beispiel:

	DLog(@"Ölstand: %f", oelstand);
	
Das Resultat sieht dann so aus: 

	[DEBUG]   Ölstand: 0.756
	
Zusätzlich zu all den Levels kann mit den Makros UILog verwendet werden. Dieses Makro zeigt den Text in einer UIAlertView an.

**Vorteil der Makros ist es, dass sie in der finalen Version automatisch nicht kompiliert werden.**


###Wechsel zwischen Makros und SMLogger
Falls Sie sich mal entscheiden von den Makros zu SMLogger oder von SMLogger zu den Makros zu wechseln, können folgende Regex hilfreich sein.

**SMLogger zu Makros** 

`\[SMLogger logDebug:(.*?)\]` ersetzen mit `DLog\(\1\)`

**Makros zu SMLogger**

`DLog\((.*?)\)` ersetzen mit `\[\[SMLogger logDebug:\1\]`
