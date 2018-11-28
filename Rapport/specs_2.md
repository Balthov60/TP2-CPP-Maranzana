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
   - intervalle complétement en dehors : **TODO**
   - borne supérieure en dehors : **TODO**
   - borne inférieure > borne supérieure : **TODO**
   - borne supérieure = borne inférieure : **TODO**
   - borne inférieure négative : **TODO**
   
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
