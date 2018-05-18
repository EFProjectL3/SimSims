# SimSims
Projet SimSims L3 Informatique Angers

SimSims v0.7

Nouveau dans cette version
- Bug de suppression fixé
- Choix du nom du fichier de sauvegarde
- Construction d'objets avancé terminé. Les "arbres" sont texturés et de forme aléatoire. Ceux ci sont définis au lancement du programme, donc ils ne sont pas sauvegardés par une save.
- Choix de création lumière positionnelle / directionnelle (à vérifier avec les ombres)
- Popup d'information au début en attendant un processus automatique


Elements implémentés (complet)
- Lecture du fichier d'entrée
- Popup de création (lumière et objets) fonctionnels
- Signaux et slots de l'interface terminés
- Widgets OpenGL fonctionnels
- Creation, modification, suppression des lumières
- Creation, modification, suppression des objets
- Gestion du parent des objets
- Changement des textures
- Load and save depuis la barre de menu (choix du nom)
- Construction d'objets avancé (GL_TRIANGLES_STRIP). 
- Choix de création lumière positionnelle / directionnelle (à vérifier avec les ombres)


Idées et implémentations à venir
- Essayer le ray picking
- Effets (ombre)
- Résoudre les derniers bugs

Bugs connus:
- Les normales de la grosse forme ne sont pas correctes
- Les textures ne rendent pas bien: il faudrait pour cela changer tout l'ordre des sommets de toutes les formes
