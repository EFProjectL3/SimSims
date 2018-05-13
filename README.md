# SimSims
Projet SimSims L3 Informatique Angers

SimSims v0.6

Nouveau dans cette version
- Load and Save
- Modification de l'interface: simplicité de lecture et d'utilisation

Elements implémentés (complet)
- Lecture du fichier d'entrée
- Popup de création (lumière et objets) fonctionnels
- Signaux et slots de l'interface terminés
- Widgets OpenGL fonctionnels
- Creation, modification, suppression des lumières
- Creation, modification, suppression des objets
- Gestion du parent des objets
- Changement des textures
- Load and save depuis la barre de menu


Idées et implémentations à venir
- Permettre de choisir le nom du fichier de sauvegarde
- Choix de création lumière positionnelle / directionnelle
- Shared libraries pour une lecture dynamique des fichiers
- Effets (type brouillard, ombre par ex)
- Construction d'objets avancé (arbres de la forêt)
- A TESTER: toutes les façons possible de changer de parent
- Résoudre les derniers bugs

Bugs connus:
- BUG au niveau de la suppression d'un objet fils (correction supposée à tester)
- La caméra ne se déplace pas correctement (à retester)
- La pyramide ne se construit pas correctement
- Les normales de la grosse forme ne sont pas correctes
- Les textures ne rendent pas bien: il faudrait pour cela changer tout l'ordre des sommets de toutes les formes
