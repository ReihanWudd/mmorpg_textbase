using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
namespace objek
{
    class person
    {
        public string? name,skill_name;
        public string weapon_name = "none";

        public int hp, atk,weapon,skill;

        public virtual void drop()
        {
            Console.WriteLine("");
        }
        public virtual void weapon_skill()
        {
            Console.WriteLine("");

        }
    }
    class hero_warior : person
    {
        public hero_warior()
        {
            name = "warior";
            hp = 600;
            atk = 300;
            weapon_name = "iron sword";
            weapon = 60;
            skill_name = "burn sword !!";
            skill = 500;
        }

        public override void drop()
        {
            Console.WriteLine("drop all items");
        }
    }
    class hero_assasins : person
    {
        public hero_assasins()
        {
            name = "warior";
            hp = 400;
            atk = 200;
            weapon_name = "iron dagger";
            weapon = 50;
            skill_name = "burn sword !!";
            skill = 500;
        }

        public override void drop()
        {
            Console.WriteLine("drop all items");
        }
    }
    class hero_archer : person
    {
        public hero_archer()
        {
            name = "archer";
            hp = 300;
            atk = 250;
            weapon_name = "bow";
            weapon = 40;
            skill_name = "meteor rain";
            skill = 500;
        }

        public override void drop()
        {
            Console.WriteLine("drop all items");
        }
    }
    class enmy : person
    {
        public enmy()
        {
            name = "ugly goblin";
            hp = 1000;
            atk = 400;
            weapon_name = "knife";
            weapon = 30;
        }
        public override void drop()
        {
            Console.WriteLine("arrow dropped");
        }
    }
}



namespace playing
{

    class program
    {
        static void Main(string[] args)
        {
            opening();
        }
        static void opening()
        {
            Console.WriteLine("GAME START");
            Console.Write("chose your hero:\n" +
                "1. warior\n" +
                "2. assasins\n" +
                "3. archer\n" +
                "[1/2/3]:");
            int pilih_hero = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("=================================\n");

            objek.person user = new objek.person();

            if (pilih_hero == 1)
            {
                user = new objek.hero_warior();
            }
            else if (pilih_hero == 2)
            {
                user = new objek.hero_assasins();
            }
            else if (pilih_hero == 3)
            {
                user = new objek.hero_archer();
            }
            start_menu(user.hp, user.atk, user.weapon, user.weapon_name, user.name);
            progres_play(user.hp, user.atk, user.weapon, user.skill_name);

        }

        static void start_menu(int nyawa, int power_user, int weapons, string weapon_name, string ch_name)
        {
            Console.WriteLine("your character");
            Console.WriteLine(
                "char name : " + ch_name + "\n" +
                "health : " + nyawa + "\n" +
                "attack : " + power_user + "\n" +
                "weapon name : " + weapon_name + "\n" +
                "weapon power : " + weapons
                );
            Console.WriteLine("=================================\n");


        }

        static void progres_play(int nyawa,int power_user,int weapons, string skill)
        {
            
            //objek.hero_warior user = new objek.hero_warior();
            objek.enmy musuh = new objek.enmy();

            int hp_enmy = musuh.hp;
            int hp_player = nyawa;
            int atk_palyer = power_user;

            bool runing_program = true;
            int skill_turn = 0;
            while (runing_program)
            {
                Console.Write("serangan :\n1.light attack\n" +
                    "2.heavy attack\n" +
                    "[1/2] :");
                int serangan = Convert.ToInt32(Console.ReadLine());

                Random power = new Random();
                int rand_power_light = power.Next(weapons, atk_palyer - weapons*2);
                int rand_power_heavy = power.Next(100, atk_palyer + 20);
                Console.Clear();
                
                if (skill_turn == 0 )
                {
                    Console.WriteLine("");
                    
                }
                else if (skill_turn == 2)
                {
                    Console.Write("skill ready use? y/n:");
                    string skill_deal = Console.ReadLine();
                    if (skill_deal == "y")
                    {
                        Thread.Sleep(2000);
                        int total = atk_palyer * 2 + weapons;
                        hp_enmy -= total;
                        skill_turn = 0;
                        Console.WriteLine("skill name: "+skill);
                        Console.WriteLine("deal damage: " + total);
                        Console.WriteLine("enmy hp : "+hp_enmy);
                    }
                    continue;
                }
                skill_turn += 1;
                Thread.Sleep(2000);
                Console.Clear();

                if (serangan == 1)
                {
                    int rand_enmy_attack = power.Next(musuh.weapon, musuh.atk);
                    Console.WriteLine("======> light attack");
                    Console.WriteLine(rand_power_light + " damage !!");
                    hp_enmy -= rand_power_light;
                    hp_player -= rand_enmy_attack;

                    Console.WriteLine("enmy HP :" + hp_enmy);
                    if (hp_enmy > 0 && hp_player > 0)
                    {
                        Console.WriteLine("======> Next turn");
                        
                        Console.WriteLine("enmy dmg " + rand_enmy_attack);
                        Console.WriteLine("your hp :" + hp_player);
                        Console.WriteLine("\n");

                    }
                    else if (hp_enmy <= 0)
                    {
                        Console.WriteLine("enmy death !!");
                        musuh.drop();
                        runing_program = false;
                    }
                    else if (hp_player <= 0)
                    {
                        Console.WriteLine("WASTED");
                        runing_program = false;
                    }
                    
                }
                else if(serangan == 2)
                {
                    Console.WriteLine("======> heavy attack");
                    Console.WriteLine(rand_power_heavy + " damage !!");
                    hp_enmy -= rand_power_heavy;

                    Console.WriteLine("enmy HP :" + hp_enmy);
                    if (hp_enmy > 0 && hp_player > 0)
                    {
                        Console.WriteLine("======> Next turn");
                        for (int i = 0; i <= 1; i++) 
                        {
                            int rand_enmy_attack = power.Next(musuh.weapon, musuh.atk);
                            hp_player -= rand_enmy_attack;
                            Console.WriteLine("enmy dmg " + rand_enmy_attack);
                            Console.WriteLine("your hp :" + hp_player);
                            Console.WriteLine("\n");
                        }
                        if (hp_player <= 0)
                        {
                            Console.WriteLine("WASTED");
                            runing_program=false;
                            break;
                        }

                    }
                    else if (hp_enmy <= 0)
                    {
                        Console.WriteLine("enmy death !!");
                        musuh.drop();
                        runing_program = false;
                    }
                  
                }
               
            }

        }
       
        

    }

}
