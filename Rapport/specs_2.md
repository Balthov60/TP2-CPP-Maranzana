### Specs

#### Gestion des noms de fichiers
Nom choisi par l'utilisateur. Doit être un nom de fichier linux valide, sinon redemande un nom de fichier.

#### Cas limites (à tester !)

- Chargement :
 - Fichier qui commence par 0;0, pas de chargement
 - Trajets doublons : pas ajoutés
- Sauvegarde :
 - catalogue vide : pas de sauvegarde
- Criterion :
 - TypeCriterion : basé sur le type de trajet "père"
 - CityCriterion : pas sensible à la casse en-US (uppercase/lowercase, mais accents importants)
 - IntervalCriterion : 
   - intervalle complétement en dehors : pas de sélection (check metadata return false)
   - borne supérieure en dehors : on met borne sup = -1, pas de limite de fin
   - borne inférieure > borne supérieure : on met borne sup = -1, pas de limite de fin
   - borne supérieure = borne inférieure : selection 1 seul ligne d'index m (n)
   - borne inférieure négative : on met borne inf = 0, traitremnt as usual
   
#### Format de sauvegarde

demo.txt :

    2;1
    Lyon;1;Bordeaux
    Lyon;2;Paris
    Lyon;3;Marseille:Paris
    	Marseille;4;Paris

Metadata : 
- Première ligne : nb trajets simples; nb trajets composés
- A la fin de première ligne de chaque trajet composé : ville d'arrivée