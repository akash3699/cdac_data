export class Emp
{
   private no: number;
   private name:string;
   private address:string;

    constructor(num:number, nm:string, addr?:string){
        this.no = num;
        this.name = nm;
        if(addr == undefined)
        {
            this.address = "pune";
        }
        else
        {
            this.address = addr;
        }
    }

   Print()
   {
       console.log(this.no, this.name, this.address);
   }
}

