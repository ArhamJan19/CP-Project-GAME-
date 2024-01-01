#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

char Class_choice;
int Quest_counter = 0;
int quest_choice =0;
int random_counter = 0;
bool fled = 0;

struct Player
{
    string Name;
    string Class;
    int health;
    int Experience;
    string inventory[10];
    int level;
    string Game_LOG;
    int Max_Health=100;
};



struct Quest
{
    string description;
    int Difficulty;
    int Experience_Reward; 
    string Artifact;
    string boss_name;
};

void create_Character(Player& player);
bool check_name(const Player &player);
void display_Character_Info(Player& player);
void Main_menu();
void Handle_main_choice(Player& player);
void Embark_on_quest(Player& player);
void Battle(Player& player, Quest& quest);
void Level_Up(Player& player);
void Rest(Player& player);
void Story_line(Player &player);
void random_events(Player &player, int &enemy_health, Quest &quest);
void Inventory();


int main()
{
    srand(time(0));

    Player Character;
    create_Character(Character);

    while (1)
    {
        Story_line(Character);
        display_Character_Info(Character);
        Main_menu();
        Handle_main_choice(Character);
    }

    cout << "\n\n";
    system("pause");
    return 0;
}

void create_Character(Player& player)
{
    bool flag = 0;
    do {
        cout << "\n\nEnter your Name: ";
        getline(cin, player.Name);
        cin.ignore();

        flag = check_name(player);


    } while (flag != 1);

    do
    {
        cout << "\n\nChoose Your Class: ";
        cout << "\n1.Saiyan\n2.Ninja\n3.Knight";
        cout << "\n\nEnter Your Choice: ";
        cin >> Class_choice;

        switch (Class_choice)
        {
        case '1':
            player.Class = "Saiyan";
            break;
        case '2':
            player.Class = "Ninja";
            break;
        case '3':
            player.Class = "Knight";
            break;
        default:
            cout << "\n\nPlease Choose a Class from the list.";
            
        }

    } while (Class_choice != '1' && Class_choice != '2' && Class_choice != '3');

    player.Experience = 0;
    player.health = player.Max_Health;
    
    player.level = 1;
    player.Game_LOG = "\n\n----------GAME LOG----------\n\n";
    
}

bool check_name(const Player& player)
{
   int character_counter = 0;

    for (int i = 0; i < player.Name.length(); i++)
    {
        if (isalpha(player.Name[i]))
        {
            character_counter++;
        }
    }

    if (character_counter >= 3)
    {
        return 1;
    }
    else
    {
        cout << "\n\nPlease Enter At lease 3 Characters in your name.";
        return 0;
    }

}

void display_Character_Info(Player& player)
{
    cout << "\n\n-----Character Information-----";
    cout << "\n\nName: " << player.Name;
    cout << "\nClass: " << player.Class;
    cout << "\nExperience: " << player.Experience;
    cout << "\nHealth: " << player.health;
    cout << "\nLevel: " << player.level;
    cout << "\n\n" << player.Game_LOG;

    cout << "\n\n---------Inventory---------";
    for (int i = 0; i < 10; ++i)
    {
        cout << endl;
        cout << i + 1 << ". " << player.inventory[i];
    }
}

void Main_menu()
{
    cout << "\n\n-----Main Menu-----";
    cout << "\n\n1.Embark on a Quest.";
    cout << "\n2.Leave the Game.";
    cout << "\n3.Rest.";
    cout << "\n4.Open Inventory";
}

void Handle_main_choice(Player &player)
{
    char main_choice;

    cout << "\n\nEnter Your Choice: ";
    cin >> main_choice;

    switch (main_choice)
    {
    case '1':
        Embark_on_quest(player);
        break;
    case '2':
        cout << "\n\nThank You For Playing Adventure Time.";
        exit(0);
    case '3':
        Rest(player);
        break;
    case '4':
        Inventory();
        break;
    default:
        cout << "\nChoose a valid choice";
        Main_menu();
        Handle_main_choice(player);
    }

}

void Embark_on_quest(Player &player)
{
   
    Quest quests_Saiyan[] = { 
                       {"Fight with Nappa", 1 , 25 , "A Dragon Ball","Nappa"},

                       {"Fight with Vegeta", 2 , 50 , "A Dragon Ball","Vegeta"},

                       {"Fight with Captain Ginyu", 3 , 100 , "A Dragon Ball","Captain Ginyu"},

                       {"Fight with Freeza", 4 , 150 ,"A Dragon Ball","Freeza"},

                       {"Fight with Shenron the dragon", 5 , 200 ,"A Dragon Ball","Shenron"}


    };
    Quest quests_Ninja[] = {
                      {"A battle with the Mizukage", 1 , 25 , "Demon Sword","Mei Mei"},

                      {"A battle with the Kazekage", 2 , 50 , "Magic Sand Pot","Gaara"},

                      {"A battle with the Raikage", 3 , 100 , "Lightning Bolt","Darui"},

                      {"A battle with the Tsuchikage", 4 , 150 ,"Golems' Blueprints","Onoki"},

                      {"A battle with the Hokage", 5 , 200 ,"Hokage's Hat","Naruto"}

    };
    Quest quests_Knight[] = {
                     {"Escorting a noble", 1 , 25 , "Goblin Bag","Goblin"},

                     {"Trial of Valor", 2 , 50 , "Ancient Helmet","JIN"},

                     {"Rescue Mission", 3 , 100 , "Healing-Potion","Voradon"},

                     {"Beast Hunt", 4 , 150 ,"Beast Skin","Ghoul"},

                     {"Slay the dragon", 5 , 200 ,"Dragon-Scale","Dragon"}

    };

    if (Class_choice == '1')
    {

        for (int i = 0; i < sizeof(quests_Saiyan) / sizeof(quests_Saiyan[i]); ++i)
        {
            cout << "\n" << i + 1 << ". " << quests_Saiyan[i].description << ", (Difficulty: " << quests_Saiyan[i].Difficulty << ")";
        }

    }
   
    else if (Class_choice == '2')
    {

        for (int i = 0; i < sizeof(quests_Ninja) / sizeof(quests_Ninja[i]); ++i)
        {
            cout << "\n" << i + 1 << ". " << quests_Ninja[i].description << ", (Difficulty: " << quests_Ninja[i].Difficulty << ")";
        }
    }

    else
    {
        for (int i = 0; i < sizeof(quests_Knight) / sizeof(quests_Knight[i]); ++i)
        {
            cout << "\n" << i + 1 << ". " << quests_Knight[i].description << ", (Difficulty: " << quests_Knight[i].Difficulty << ")";
        }
    }

 

    cout << "\n\nEnter your choice: ";
    cin >> quest_choice;

    Quest Selected_Quest;
    
    if (Class_choice == '1')
    {
        Selected_Quest = quests_Saiyan[quest_choice - 1];
    }
    else if (Class_choice == '2')
    {
        Selected_Quest = quests_Ninja[quest_choice - 1];
    }
    else
    {
        Selected_Quest = quests_Knight[quest_choice - 1];
    }

    Battle(player, Selected_Quest);
}

void Battle(Player& player, Quest& quest)
{
    int enemy_health = player.health * quest.Difficulty;
    int Player_Attack = 0;
    int Enemy_Attack = 0;


    cout << "\n\n-----Battle Begins-----";
   

    while (player.health > 0 && enemy_health > 0)
    {
        cout << "\n------------------------";
        cout << "\n\n"<<player.Name<<" Health: " << player.health;
        cout << "\n"<<quest.boss_name<<"'s Health: " << enemy_health;
        cout << "\n------------------------";

        cout << "\n\n-----" << player.Name << "'s Turn-----";

        cout << "\n\n\n------Choose Your Attack----- ";
        cout << "\n\n1.Heavy Attack";
        cout << "\n2.Light Attack";
        cout << "\n3.Flee from the Battle";

        char attack_choice;
        cout << "\n\nEnter Your Choice: ";
        cin >> attack_choice;

        if (attack_choice == '1')
        {
            Player_Attack = rand() % (player.level * 50) + 1;
        }
        else if (attack_choice == '2')
        {
            Player_Attack = rand() % (player.level * 30) + 1;
        }

        else if (attack_choice == '3')
        {
            if (player.health < 50)
            {
                int exit_choice;
                cout << "\n\nYou tried to escape but the Beast Killed You.";
                cout << "\n\nGame Over!";
                cout << "\n\nPress (0) to exit?";
                cout << "\n\nPress any other key to continue.";
                cout << "\n\nEnter your choice :  ";
                cin >> exit_choice;

                if (exit_choice == 0)
                {
                    exit(0);
                }
                else
                {
                    main();
                }

               
            }
            else
            {
                cout << "\n\nYou successfully escaped from the Creature.";
                Main_menu();
                return;
            }
        }

        else
        {
            Battle(player, quest);
        }

        if (attack_choice != '3') 
        {
            enemy_health -= Player_Attack;
            cout << "\n\nYou Inflicted a Damage of " << Player_Attack << " on " << quest.boss_name;

            int c_attack = rand() % 3 + 1;

            cout << "\n\n-----" << quest.boss_name <<"'s Turn-----";

            if (c_attack == 3)
            {
                cout << "\n\n" << quest.boss_name << " fled from the battle ground.";
                fled = 1;
                break;
            }
            else if (c_attack == 1)
            {
                Enemy_Attack = rand() % (quest.Difficulty * 30) + 1;
            }
            else
            {
                Enemy_Attack = rand() % (quest.Difficulty * 20) + 1;
            }

            player.health -= Enemy_Attack;
           
            cout << "\n\nThe " << quest.boss_name << " Inflicted a Damage of " << Enemy_Attack << " on You.";
            
            if (random_counter == 0)
            {
                random_events(player, enemy_health, quest);
            }
            
        }
    }

    if (enemy_health < 0 || fled == 1)
    {
        cout << "\n\nYou Won the Battle!";
        player.Experience += quest.Experience_Reward;

        if (player.Experience >= 100)
        {
            Level_Up(player);
        }
        
        player.inventory[quest_choice - 1] = quest.Artifact;
        cout << "\nItem Obtained: " << player.inventory[quest_choice - 1];
        player.Game_LOG += "\nCompleted: " + quest.description;
        random_counter = 0;
        Quest_counter++;
        cout << endl;
        Main_menu();
        
    }
    else
    {
        cout << "\n\nYou Lost!!!";
        player.Game_LOG += "\nLOST: " + quest.description;
        random_counter = 0;
        Quest_counter++;

    }

}

void Level_Up(Player& player)
{
    player.level++;
    player.Experience = 0;
    player.Max_Health += 100;
}

void Rest(Player& player)
{
    player.health = player.Max_Health;
    cout << "\nA Warrior Needs his Rest.";
    Main_menu();
}

void Story_line()
{
    if (Quest_counter == 0)
    {
        cout << "\n\nFuck YOu!!!";
    }
}

void random_events(Player &player, int &enemy_health, Quest &quest )
{
    bool random_number = (rand() % 2);
   

    if (random_number == 1)
    {
        random_counter++;
        
        string event;

        cout << "\n\nA Random Event has Occured.";

        int random = rand() % 4 + 1;

           if(random == 1)
           {

                int a, b, tries = 0 , correct_counter = 0, wrong_counter = 0;

                enemy_health -= 50;

                 event= "\n\nThe " +  quest.boss_name +  " sets up cunning traps in the surrounding area.\nThe " + quest.boss_name + " sacrificed his health points to setup this trap,\nguess the locations of the mines to avoid getting injured and further losing your Health Points.";
                    
                 cout << "\n\n" << event;

                 cout << "\n\nYour Health: " << player.health;
                 cout << "\n\n" << quest.boss_name << "'s Health: " << enemy_health;

                int maze_1[3][3] = {

                    {1,0,1},
                    {0,1,1},
                    {1,1,0}
                };

                int maze_2[3][3] = {

                    {0,1,0},
                    {1,1,1},
                    {1,0,1}
                };

                int maze_3[3][3] = {

                    {1,1,0},
                    {1,0,1},
                    {0,1,1}
                };

                int mazes = rand() % 3 + 1;

                    cout << "\n\n  --------MAZE--------\n\n";

                    for (int i = 0; i < 3; i++)

                    {
                        cout << "\t";
                        for (int j = 0; j < 3; j++)
                        {
                            cout <<"* ";
                        }
                        cout << endl;
                    }
                
                    if (mazes == 1)
                    {

                        cout << "\n\nYou have 3 tries.";

                        for (int i = 0; i < 3; i++)
                        {
                            cout << "\n\nEnter the location of Mine " << i + 1 << ": ";
                            cin >> a >> b;
                            if (maze_1[a-1][b-1] == 0)
                            {
                                cout << "\n\nYou have spotted the Mine " << i + 1 << ".";
                                correct_counter++;
                            }
                            else
                            {
                                cout << "\n\nYour guess was wrong:";
                                cout << "\n\nYour Health was reduced By 10.";
                                player.health -= 10;
                                cout << "\n\nYour Health: " << player.health;
                                wrong_counter++;
                            }
                        }
                    }

                    else if (mazes == 2)
                    {

                        cout << "\n\nYou have 3 tries.";

                        for (int i = 0; i < 3; i++)
                        {
                            cout << "\n\nEnter the location of Mine " << i + 1 << ": ";
                            cin >> a >> b;
                            if (maze_2[a-1][b-1] == 0)
                            {
                                cout << "\n\nYou have spotted Mine " << i + 1 << ".";
                                correct_counter++;
                            }
                            else
                            {
                                cout << "\n\nYour guess was wrong:";
                                cout << "\n\nYour Health was reduced By 10.";
                                player.health -= 10;
                                cout << "\n\nYour Health: " << player.health;
                                wrong_counter++;
                            }
                        }
                    }

                    else if (mazes == 3)
                    {

                        cout << "\n\nYou have 3 tries.";

                        for (int i = 0; i < 3; i++)
                        {
                            cout << "\n\nEnter the location of Mine " << i + 1 << ": ";
                            cin >> a >> b;
                            if (maze_3[a-1][b-1] == 0)
                            {
                                cout << "\n\nYou have spotted Mine " << i + 1 << ".";
                                correct_counter++;
                            }
                            else
                            {
                                cout << "\n\nYour guess was wrong:";
                                cout << "\n\nYour Health was reduced By 10.";
                                player.health -= 10;
                                cout << "\n\nYour Health: " << player.health;
                                wrong_counter++;
                            }
                        }
                    }

                   
                    player.Game_LOG += "\nThe " + quest.boss_name +" sets up a Trap.";
                    player.Game_LOG += "\nYou correctly Guessed " + to_string(correct_counter) + " traps.";
                    player.Game_LOG += "\nHealth reduced " + to_string(wrong_counter * 10);

           }

            else if (random == 2)
            {
                random_counter++;
                bool your_guess = 0;
                event = quest.boss_name + " wants to Test your wisdom.He gives you a riddle to solve.";
                cout << "\n\n" << event;

                int riddles = rand() % 3 + 1;
               

                if (Class_choice == '1')
                {
                    if (riddles == 1)
                    {
                        string answer = "rage";
                        string user_answer = "";
                        cout << "\n\nRiddle: I am an unstoppable force, born from fury's embrace. What form do I take?";
                        cout << "\n\nGive it your best shot (Enter your answer in lower-case letters): ";
                        cin >> user_answer;

                        if (user_answer == answer)
                        {
                            cout << "\n\nYour Guess was Correct.";
                            player.Experience += quest.Experience_Reward;
                            player.health += 20;
                            enemy_health -= 20;
                            your_guess = 1;
                        }
                        else
                        {
                            cout << "\n\nYour Guess was not Correct.";
                           
                            player.health -= 20;
                            enemy_health += 15;
                        }
                        
                    }
                    else if (riddles == 2)
                    {
                        string answer = "warrior";
                        string user_answer = "";
                        cout << "\n\nRiddle:I rise with a golden aura, transcending limits with each battle's heat. Who am I?";
                        cout << "\n\nGive it your best shot (Enter your answer in lower-case letters without space): ";
                        cin >> user_answer;

                        if (user_answer == answer)
                        {
                            cout << "\n\nYour Guess was Correct.";
                            player.Experience += quest.Experience_Reward;
                            player.health += 20;
                            enemy_health -= 20;
                            your_guess = 1;
                        }
                        else
                        {
                            cout << "\n\nYour Guess was not Correct.";

                            player.health -= 20;
                            enemy_health += 15;
                        }
                    }
                    else
                    {
                        string answer = "superpower";
                        string user_answer = "";
                        cout << "\n\nRiddle:Born of stars, I wield the power to shake worlds. What am I?";
                        cout << "\n\nGive it your best shot (Enter your answer in lower-case letters): ";
                        cin >> user_answer;

                        if (user_answer == answer)
                        {
                            cout << "\n\nYour Guess was Correct.";
                            player.Experience += quest.Experience_Reward;
                            player.health += 20;
                            enemy_health -= 20;
                            your_guess = 1;
                        }
                        else
                        {
                            cout << "\n\nYour Guess was not Correct.";

                            player.health -= 20;
                            enemy_health += 15;
                        }
                    }
                }

                else if (Class_choice == '2')
                {
                    if (riddles == 1)
                    {
                        string answer = "stealth";
                        string user_answer = "";
                        cout << "\n\nRiddle:  I vanish in the shadows, a ghost in the night. What hides within?";
                        cout << "\n\nGive it your best shot (Enter your answer in lower-case letters): ";
                        cin >> user_answer;

                        if (user_answer == answer)
                        {
                            cout << "\n\nYour Guess was Correct.";
                            player.Experience += quest.Experience_Reward;
                            player.health += 20;
                            enemy_health -= 20;
                            your_guess = 1;
                        }
                        else
                        {
                            cout << "\n\nYour Guess was not Correct.";

                            player.health -= 20;
                            enemy_health += 15;
                        }

                    }
                    else if (riddles == 2)
                    {
                        string answer = "shadow";
                        string user_answer = "";
                        cout << "\n\nRiddle:I am the master of concealment, adept in the art of surprise. Who am I?";
                        cout << "\n\nGive it your best shot (Enter your answer in lower-case letters without space): ";
                        cin >> user_answer;

                        if (user_answer == answer)
                        {
                            cout << "\n\nYour Guess was Correct.";
                            player.Experience += quest.Experience_Reward;
                            player.health += 20;
                            enemy_health -= 20;
                            your_guess = 1;
                        }
                        else
                        {
                            cout << "\n\nYour Guess was not Correct.";

                            player.health -= 20;
                            enemy_health += 15;
                        }
                    }
                    else
                    {
                        string answer = "invisibility";
                        string user_answer = "";
                        cout << "\n\nRiddle: I move with silent footsteps, unseen yet omnipresent. What skill am I?";
                        cout << "\n\nGive it your best shot (Enter your answer in lower-case letters): ";
                        cin >> user_answer;

                        if (user_answer == answer)
                        {
                            cout << "\n\nYour Guess was Correct.";
                            player.Experience += quest.Experience_Reward;
                            player.health += 20;
                            enemy_health -= 20;
                            your_guess = 1;
                        }
                        else
                        {
                            cout << "\n\nYour Guess was not Correct.";

                            player.health -= 20;
                            enemy_health += 15;
                        }
                    }
                }


                else 
                {
                    if (riddles == 1)
                    {
                        string answer = "defender";
                        string user_answer = "";
                        cout << "\n\nRiddle:Clad in steel, I am a guardian of realms. What's my calling?";
                        cout << "\n\nGive it your best shot (Enter your answer in lower-case letters): ";
                        cin >> user_answer;

                        if (user_answer == answer)
                        {
                            cout << "\n\nYour Guess was Correct.";
                            player.Experience += quest.Experience_Reward;
                            player.health += 20;
                            enemy_health -= 20;
                            your_guess = 1;
                        }
                        else
                        {
                            cout << "\n\nYour Guess was not Correct.";

                            player.health -= 20;
                            enemy_health += 15;
                        }

                    }
                    else if (riddles == 2)
                    {
                        string answer = "knight";
                        string user_answer = "";
                        cout << "\n\nRiddle:I am the wielder of chivalry's might, shining under the sun's gleam. What am I?";
                        cout << "\n\nGive it your best shot (Enter your answer in lower-case letters without space): ";
                        cin >> user_answer;

                        if (user_answer == answer)
                        {
                            cout << "\n\nYour Guess was Correct.";
                            player.Experience += quest.Experience_Reward;
                            player.health += 20;
                            enemy_health -= 20;
                            your_guess = 1;
                        }
                        else
                        {
                            cout << "\n\nYour Guess was not Correct.";

                            player.health -= 20;
                            enemy_health += 15;
                        }
                    }
                    else
                    {
                        string answer = "protector";
                        string user_answer = "";
                        cout << "\n\nRiddle: My heart beats with loyalty, my blade sings with honor. Who am I?";
                        cout << "\n\nGive it your best shot (Enter your answer in lower-case letters): ";
                        cin >> user_answer;

                        if (user_answer == answer)
                        {
                            cout << "\n\nYour Guess was Correct.";
                            player.Experience += quest.Experience_Reward;
                            player.health += 20;
                            enemy_health -= 20;
                            your_guess = 1;
                        }
                        else
                        {
                            cout << "\n\nYour Guess was not Correct.";

                            player.health -= 20;
                            enemy_health += 15;
                        }
                    }
                }

                event = quest.boss_name + " asked you a Riddle.";
                
                if (your_guess == 1)
                {
                    player.Game_LOG += "\n\nYour guess was Correct.";
                }
                else
                {
                    player.Game_LOG += "\n\nYour guess was not Correct.";
                }
            }

            else if(random == 3)
            {
                cout << "\n\nA Natural Disaster Occured reducing the health both " << player.Name << " and " << quest.boss_name;
                player.health -= 20;
                enemy_health -= 20;

                cout <<"\n" << player.Name << "'s Health: " << player.health;
                cout <<"\n" << quest.boss_name << "'s Health: " << enemy_health;

                event = "A Natural Disaster Occured reducing the health of both " + player.Name + " and " + quest.boss_name;
                player.Game_LOG += event + "\n" + player.Name + " and " + quest.boss_name + " was reduced by 20.";
            }

            else
            {
                event = "In the midst of our heated clash, a sudden interruption shattered the tension as a neutral third party,\n unforeseen and enigmatic, emerged into our battleground.";
                cout << "\n\n" << event;

                int third_party = rand() % 2 + 1;
                int damage = rand() % 30 + 1;

                if (third_party == 1)
                {
                    enemy_health -= damage;
                    cout << "\n\n" << player.Name << "'s Ally came to his help,inflicting a damage of " << damage <<" on " << quest.boss_name;
                    player.Game_LOG += "\n" + event + " and inflicted a damage of " + to_string(damage) + " on " + quest.boss_name;

                }
                else
                {
                    player.health -= damage;
                    cout << "\n\n" << quest.boss_name << "'s Ally came to his help,inflicting a damage of " << damage << " on " << player.Name;
                    player.Game_LOG += "\n" + event + " and inflicted a damage of " + to_string(damage) + " on " + player.Name;
                
                }
               


            }
            
        
    }
    
}

void Inventory()
{
    
}

void Story_line(Player& player)
{
    if (Quest_counter == 0)
    {
        if (Class_choice == '1')
        {
            cout << "\n\nThe Saiyan protagonist embarks on a quest to rediscover their lost heritage and unlock the dormant potential within their Saiyan bloodline. The journey involves training under celestial masters to harness raw energy, seeking legendary artifacts scattered across the cosmos, and mastering the art of transformation. The ultimate goal is to awaken the legendary Super Saiyan form, a transformation of immense power, to defend the universe from impending threats.";
        }
        else if (Class_choice == '2')
        {
            cout << "\n\nThe Ninja embarks on a perilous quest to uncover ancient scrolls scattered across hidden landscapes. These scrolls contain secret techniques and ancestral knowledge crucial to preserving the ninja clan's legacy. The journey involves mastering stealth, agility, and various ninja arts while confronting rogue factions seeking to exploit these ancient secrets. The ultimate challenge lies in mastering the Forbidden Shadow Arts, unlocking their true potential, and restoring balance to the ninja world.";
        }
        else if (Class_choice == '3')
        {
            cout << "\n\nThe Knight sets forth on a quest to uphold honor and restore the tarnished reputation of their order. Their journey entails safeguarding sacred relics, seeking lost artifacts of legendary valor, and undergoing trials to prove their worthiness. The quest involves defending the kingdom from dark forces, forming alliances with noble allies, and ultimately confronting a corrupted nemesis threatening the realm. The final test is to reclaim the lost virtue of chivalry, embodying it in a decisive battle to restore peace and honor to the land.";
        }
    }
}