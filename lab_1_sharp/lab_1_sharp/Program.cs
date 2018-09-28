using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab_1_sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Person> people = new List<Person>();
            CreateGroup(ref people);
            people.Sort();
            Console.WriteLine("\nSorted people :");
            people.ForEach(person => Console.WriteLine(person.ToString()));
            Console.Read();
        }

        static void CreateGroup(ref List<Person> people)
        {
            people.Add(Person.CreatePerson());
            Console.WriteLine("Do you want to add one more? Click Enter if yes.");
            string input = Console.ReadLine();
            if(input == String.Empty)
            {
                CreateGroup(ref people);
            }
        }
    }

    class Person : IComparable<Person>
    {
        string name;
        int age;
        int score;

        public Person(string _name, int _age, int _score)
        {
            name = _name;
            age = _age;
            score = _score;
        }

        public int CompareTo(Person other)
        {
            var result = name.CompareTo(other.name);
            if (result != 0) return result;
            result = age.CompareTo(other.age);
            if (result != 0) return result;
            result = score.CompareTo(other.score);
            if (result != 0) return result;
            else return 0;
        }

        public override string ToString()
        {
            return $"\nName : {name} \nAge : {age} \nScore : {score}";
        }

        public static Person CreatePerson()
        {
            Console.Write("\nEnter the name of person : ");
            string name = Console.ReadLine();

            Console.Write("Enter the age of person : ");
            int age = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter the score of person : ");
            int score = Convert.ToInt32(Console.ReadLine());

            return new Person(name, age, score);
        }
    }
}
