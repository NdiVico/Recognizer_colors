#SCM Plan

1 **Introduction**

La seguente idea di progetto nasce con il proposito di aiutare coloro i quali presentino delle invalidità, 
al fine di garantire una percezione del mondo più completa. L'idea è quella di realizzare un riconoscitore
di colori per non vedenti e/o daltonici, predisposto con un'opportuna strumentazione per la segnalazione 
acustica in grado di permettere all'utilizzatore di riconoscere il colore dell'oggetto di riferimento. La 
realizzazione del dispositivo si basa su una scheda elettronica (Arduino) e due moduli con funzioni rispettivamente di riconoscimento dei colori e di invio della segnalazione acustica. Come ambiente di sviluppo Software è stato utilizzato l'IDE di Arduino.

2 **Management**

Il team di lavoro è composto da


- Configuration Manager: Capobianco;

- Change Control Board Member: di Vico, Luisi;

- Developer: di Vico, Luisi, Capobianco;

- Auditor: di Vico, Luisi, Capobianco

3 **Configuration items**

- Source Code
- Software Requirement Specification
- Test Data
- Input Data
- Support Software

4 **Promotion and release policies**

- Politica di promotion: il codice sorgente deve essere compilabile, senza errori o warning.

- Politica di release: deve essere effettuato il testing funzionale.

5 **Activities and Schedule**

Il rilascio del prototipo funzionante del dispositivo è prevista per 30/09/16. I costi relativi alla parte hardware del
dispositivo non superano gli 80 euro. In seguito viene riportata la successione delle attività che devono essere svolte ai
fini dell'implementazione del dispositivo stesso:

- [x] definire collegamenti hardware della scheda Arduino con i moduli di supporto;

- [x] implementazione funzioni di Arduino:

    - [x] read_color(): dovrà permettere di settare il modulo di riconoscimento dei colori per fornire i valori misurati dai
      fotodiodi per i colori rosso, verde e blu, stampandoli poi a monitor. Inoltre dovrà definire gli intervalli oppurtuni             dei 
      valori acquisiti in precedenza al fine di identificare il rispettivo colore. Per ogni intervallo viene inserita la 
      funzione di invio dei file audio.

6 **Tools**

Come sistema di versioning verrà utilizzato Git, hosted GitHub e client SourceTree, per gestire da remoto i commit ed i push.
I file audio verranno convertiti dal formato mp3 o wav a .ad4 attraverso SOMO tool, mentre per effettuare le registrazioni
vocali verrà utilizzato un software di editing audio open source chiamato AUDACITY.
