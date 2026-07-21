#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char * federations[] = {"Afghanistan", "Albania", "Algeria", "American_Samoa", "Andorra", "Angola", "Antigua_and_Barbuda", "Argentina", "Armenia", "Australia", "Austria", "Azerbaijan", "Bahamas", "Bahrain", "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin", "Bhutan", "Bolivia", "Bosnia_and_Herzegovina", "Botswana", "Brazil", "British_Virgin_Islands", "Brunei", "Bulgaria", "Burkina_Faso", "Burundi", "Cambodia", "Cameroon", "Canada", "Cape_Verde", "CAR", "Cayman_Islands", "Chad", "Chile", "Colombia", "Comoros", "Congo", "Cook_Islands", "Costa_Rica", "Côte_d'Ivoire", "Croatia", "Cuba", "Cyprus", "Czechia", "Denmark", "Djibouti", "Dominica", "Dominican_Republic", "DPR_Korea", "DR_Congo", "Ecuador", "Egypt", "El Salvador", "England", "Equatorial_Guinea", "Estonia", "Eswatini", "Ethiopia", "Faroe_Islands", "Fiji", "Finland", "France", "FS_Micronesia", "Gabon", "Gambia", "Georgia", "Germany", "Ghana", "Great_Britain", "Greece", "Greenland", "Grenada", "Guadeloupe", "Guam", "Guatemala", "Guiana", "Guinea", "Guinea-Bissau", "Guyana", "Haiti", "Honduras", "Hong_Kong", "Hungary", "Iceland", "India", "Indonesia", "IR_Iran", "Iraq", "Ireland", "Israel", "Italy", "Jamaica", "Japan", "Jordan", "Kazakhstan", "Kenya", "Kiribati", "Korea_Republic", "Kosovo", "Kuwait", "Kyrgystan", "Lao_PDR", "Latvia", "Lebanon", "Lesotho", "Liberia", "Liechtenstein", "Lithuania", "Luxembourg", "Libya", "Macao", "Madagascar", "Malawi", "Malaysia", "Maldives", "Mali", "Malta", "Marshall_Islands", "Martinique", "Mauritania", "Mauritius", "Mayotte", "Mexico", "Moldova", "Monaco", "Mongolia", "Montenegro", "Morocco", "Mozambique", "Namibia", "Nauru", "Nepal", "Netherlands", "New_Caledonia", "New_Zealand", "Nicaragua", "Niger", "Nigeria", "North_Macedonia", "Northern_Mariana_Islands", "Norway", "Oman", "Pakistan", "Palau", "Palestine", "Panama", "Papua_New_Guinea", "Paraguay", "Peru", "Phillipines", "Poland", "Portugal", "PR_China", "Puerto_Rico", "Qatar", "Réunion", "Romania", "Russia", "Rwanda", "Saint_Kitts_and_Nevis", "Saint_Lucia", "Samoa", "São_Tomé_e_Príncipe", "Saudi_Arabia", "Scotland", "Senegal", "Serbia", "Seychelles", "Sierra_Leone", "Singapore", "Slovakia", "Slovenia", "Solomon_Islands", "Somalia", "South_Africa", "South_Sudan", "Spain", "Sri_Lanka", "Sudan", "Sweden", "Switzerland", "Syria", "Tahiti", "Taipei", "Tajikistan", "Tanzania", "Thailand", "Timor-Leste", "Togo", "Tonga", "Trinidad_and_Tobago", "Tunisia", "Türkiye", "Turkmenistan", "Tuvalu", "UAE", "Uganda", "Ukraine", "Uruguay", "USA", "Uzbekistan", "Vanuatu", "Venezuela", "Vietnam", "Yemen", "Zambia", "Zimbabwe"};
    FILE * all = fopen("allcountries", "w");
    for (int i = 0; i < 211; i++) {
        FILE * country = fopen(federations[i], "r");
        char buffer[1024];
        float elo = atof(fgets(buffer, sizeof buffer, country));
        fclose(country);
        buffer[0] = '\0';
        fprintf(all, "%s: %f elo\n", federations[i], elo);
        
    }
    fclose(all);
    printf("All done!");
}