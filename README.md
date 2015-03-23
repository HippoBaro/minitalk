#L'essentiel de mon projet:
    * Client et serveur de communication utilisant les signaux POSIX.
    * Fonctionnemnt inspiré du protocole TCP (ping-pong).
    * Transfert ultra rapide. Bande passante d'environ 70 Ko/s sur mon
      système. ~40 secondes pour transferer un livre entier de Proust.
    * Gestion de UTF-8 (multi-byte chars).
    * Gestion de plusieurs clients à la suite (persistance du serveur).
    * Utilisation du CPU nulle en l'absence de connexion active.
    * Code propre, clair et optimisé au maximum (de mes compétences).
    * Pas de gestion du multi-client.
    * Une variable globale par binaire justifié par l'absence de moyen
      de passer en parametre une variable quelqueconque au handler
      de signal défini par signal().
    * Un valgrind impeccable (pas de fuite, pas d'erreur).
    * Un code clair et optimisé.

#Les bonus implémentés :
    * Gestion du time-out (de cinq secondes par défaut) en l'absence de
      réponse du serveur.
    * Gestion de la corruption des données. Un checksum est effectué avant
      l'envoi, puis l'opération est répété après réception pour assurer
      l'intégrité du transfert. (la méthode de checksum est une adaptation
      de celle de l'objet string en Java, elle est très simple,
      performante mais ne convient pas pour des proto de sécurité).
    * Retry automatique en cas de corruption avéré.
    * Gestion des collisions de signaux (si un client à la mauvaise idée de
      tenter un transfert alors qu'un autre est en cours).
    * Informations complètes sur le transfert : bande passante, pourcentage,
      temps restant estimé et meme une sublime progressbar home-made
    * Si la chaine passé au client correspond à un fichier sur le filesystem,
      c'est le contenu de se fichier qui est transferé.

#Note au correcteur :

Le fichier 'proust' contient l'oeuvre complète de Marcel Proust, À l’ombre des
jeunes filles en fleurs. Il pèse environ 1.3 Mo et permet de tester facilement
le serveur et le client avec de grosses data, mais aussi les collisions et les
corruptions de données qu'elles entrainent.

	    ./client/client [PID] "proust"

With love,
barrau_h.
