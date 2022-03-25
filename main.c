
using System;

namespace objek 
{
    class person 
    {
        public string? name;
        public int hp, atk;

    }
    class hero : person
    {
        public hero()
        {
            name = "warior";
            hp = 500;
            atk = 200;
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
    }
}



namespace playing
{
    class user_menyerang 
    {
        
    }
    class program 
    {
        static void Main(string[] args) 
        {
            bool runing_program = true;
            while (runing_program) 
            {
                Console.Write("serangan light ,heavy [1/2] :");
                int serangan = Convert.ToInt32(Console.ReadLine());

                objek.hero user = new objek.hero();
                objek.enmy musuh = new objek.enmy();

                
                Random power = new Random();
                int rand_power_light = power.Next(25, user.atk);
                int rand_power_heavy = power.Next(100, user.atk);
                int rand_enmy_attack = power.Next(20,musuh.atk);
                
                if (serangan == 1)
                {
                    Console.WriteLine("light attack");
                    Console.WriteLine(rand_power_light + " damage !!");
                    musuh.hp -= rand_power_light;
                    
                    Console.WriteLine("enmy HP :" + musuh.hp);
                    if (musuh.hp > 0)
                    {
                        Console.WriteLine("Next turn");
                        user.hp -= rand_enmy_attack;
                        Console.WriteLine("enmy dmg" + rand_enmy_attack);
                        Console.WriteLine("your hp :"+ user.hp);
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










namespace interaction
{
    class serangan_user
    {
        //public void user_ke_enmy()
        //{
        //    Console.WriteLine("light attack");
        //    Console.WriteLine(rand_power_light + " damage !!");
        //    musuh.hp -= rand_power_light;
        //    Console.WriteLine(musuh.hp);
        //    Console.WriteLine("enmy HP :" + musuh.hp);
        //    if (musuh.hp > 0)
        //    {
        //        Console.WriteLine("Next turn");
        //    }
        //    else if (musuh.hp <= 0)
        //    {
        //        Console.WriteLine("enmy death !!");
        //    }
        //}

    }
}
