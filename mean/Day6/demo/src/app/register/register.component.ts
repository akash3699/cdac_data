import { Component, OnInit } from '@angular/core';
import { DataService } from '../data.service';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent implements OnInit {
  message: string;
  constructor(private service: DataService) 
  {

  }

  ngOnInit() {
  }

  Add(DataFromUI:any)
  {
    //console.log(DataFromUI.form.value);
    let resultstate=this.service.AddData(DataFromUI.form.value);
    
    resultstate.subscribe((data:any)=>{
      if(data.error==null)
      {
      this.message = "Record Inserted!"
      }
      else{
        console.log(data);
        this.message = "Something Wrong";
      }
    }); 
  }

}






