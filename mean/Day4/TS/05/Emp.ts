
export class Emp
{

    constructor(private no:number,
                public name:string,
                private address:string="pune")
    {
        
    }

   Print()
   {
       console.log(this.no, this.name, this.address);

       for(var i =0; i< 2; i++)
       {
         let data = "something";
       }

    //    console.log(data)

   }
}






