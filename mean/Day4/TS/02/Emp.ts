export class Emp
{
   private no: number;
   private name:string;
   private address:string;

   constructor(){
       this.no = 10;
       this.name = "abc";
       this.address = "karad";
   } 

   Print()
   {
       console.log(this.no, this.name, this.address);
   }
}

