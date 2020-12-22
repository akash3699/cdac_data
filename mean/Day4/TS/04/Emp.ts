export class Emp
{
   private no: number;
   private name:string;
   private address:string;

    constructor(num:number, nm:string, addr:string="pune"){
        this.no = num;
        this.name = nm;
        this.address = addr;
    }

   Print()
   {
       console.log(this.no, this.name, this.address);
   }
}

