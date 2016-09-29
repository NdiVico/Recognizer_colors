# Recognizer_colors

- **Management**

## 1 INTRODUZIONE

La seguente idea di progetto nasce con il proposito di aiutare coloro i quali presentino delle invalidità, al fine di garantire una percezione del mondo più completa. L'idea è quella di realizzare un riconoscitore di colori per non vedenti e/o daltonici, predisposto con un'opportuna strumentazione per la segnalazione acustica in grado di permettere all'utilizzatore di riconoscere il colore dell'oggetto di riferimento.

# 2 Attività

Il sistema è stato realizzato sfruttando una scheda elettronica Arduino munita di un modulo TCS230 per il riconoscimento dei colori e di un modulo WTV020-SD-16D per realizzare la funzione vocale. L'idea è quella di utilizzare arduino per far funzionare il modulo di riconoscimento dei colori che grazie alla matrice (8x8) di fotodiodi di cui è prediposto è in grado di riconoscere il colore dell'oggetto posto in prossimità del sensore. La scheda è inoltre collegata ad un modulo in grado di leggere file audio da una microSD e trasmetterli con un semplice altoparlante, in modo tale da associare al colore acquisito dal primo modulo la registrazione vocale di qualcuno che pronuncia il colore. Come microSD è stata utilizzata una Transcendt da 1GB e al fine di garantirne la leggibilità dei file audio, questi ultimi sono stati salvati in formato .ad4.

# 3 Tools
 
I file audio sono stati convertiti dal formato mp3 o wav a .ad4 attraverso SOMO tool, mentre per effettuare le registrazioni vocali è stato utilizzato un software di editing audio open source chiamato AUDACITY.  
