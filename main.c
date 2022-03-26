using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace objek
{
    class person
    {
        public string? name, weapon;
        public int hp, atk;

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
            weapon = "iron sword";
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
            weapon = "iron dagger";
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
            weapon = "bow";
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
            name = "stone";
            hp = 2000;
            atk = 50;
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

            int health = 0;
            int attack = 0;

            if (pilih_hero == 1)
            {
                objek.hero_warior user = new objek.hero_warior();
                health = user.hp;
                attack = user.atk;
            }
            else if (pilih_hero == 2)
            {
                objek.hero_assasins user = new objek.hero_assasins();
                health = user.hp;
                attack = user.atk;
            }
            else if (pilih_hero == 3)
            {
                objek.hero_archer user = new objek.hero_archer();
                health = user.hp;
                attack = user.atk;
            }
            progres_play(health,attack);
        }

        static void progres_play(int nyawa,int power_user)
        {
            
            objek.hero_warior user = new objek.hero_warior();
            objek.enmy musuh = new objek.enmy();

            int hp_enmy = musuh.hp;
            int hp_player = nyawa;
            int atk_palyer = power_user;
            

            bool runing_program = true;
            while (runing_program)
            {
                Console.Write("serangan light ,heavy [1/2] :");
                int serangan = Convert.ToInt32(Console.ReadLine());

                Random power = new Random();
                int rand_power_light = power.Next(25, atk_palyer - 50);
                int rand_power_heavy = power.Next(100, atk_palyer);
                int rand_enmy_attack = power.Next(20, musuh.atk);

                if (serangan == 1)
                {
                    Console.WriteLine("light attack");
                    Console.WriteLine(rand_power_light + " damage !!");
                    hp_enmy -= rand_power_light;

                    Console.WriteLine("enmy HP :" + hp_enmy);
                    if (musuh.hp > 0)
                    {
                        Console.WriteLine("Next turn");
                        hp_player -= rand_enmy_attack;
                        Console.WriteLine("enmy dmg" + rand_enmy_attack);
                        Console.WriteLine("your hp :" + hp_player);
                        Console.WriteLine("\n");

                    }
                    else if (musuh.hp <= 0)
                    {
                        Console.WriteLine("enmy death !!");
                    }
                }
                else if (serangan == 2)
                {
                    Console.WriteLine("heavy attack");
                    Console.WriteLine(rand_power_heavy + " damage !!");

                    musuh.hp -= rand_power_heavy;
                    Console.WriteLine("enmy HP :" + musuh.hp);
                    if (musuh.hp > 0)
                    {
                        Console.WriteLine("Next turn");
                    }
                    else if (musuh.hp <= 0)
                    {
                        Console.WriteLine("enmy death !!");
                    }

                }
                else
                {
                    Console.WriteLine("salah tombol !!");
                }


            }

        }
        

    }

}
