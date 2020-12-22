import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { DataService } from '../data.service';

@Component({
  selector: 'app-edit',
  templateUrl: './edit.component.html',
  styleUrls: ['./edit.component.css']
})
export class EditComponent implements OnInit 
{
  emp;
  message;

  constructor(public routes:ActivatedRoute,
              public service: DataService,
              public router: Router) 
  {
    this.message = "";  
  }

  ngOnInit() 
  {
    let parameterArrivalStatus = this.routes.paramMap;

    parameterArrivalStatus.subscribe((params)=>{
      let No = params.get("No");
      //console.log(params.get("No"));
      let StatusofEmpSearched= this.service.GetDataByID(No);

      StatusofEmpSearched.subscribe((result:any)=>{
        
        if(result.length>0)
        {
          this.emp = result[0];
          //console.log(this.emp.name);
          this.message = "Record found!"
          
        }
        else
        {
          this.message = "Record not found!"
        }
      }); 

    });
  }

  Update()
  {
    let statusOfUpdate= this.service.UpdateData(this.emp);
    statusOfUpdate.subscribe((result:any)=>{
      //console.log(result);
      if(result.affectedRows>0)
      {
        this.router.navigate(['home']);
      }
      else{
        this.message = "Something went wrong!";
      }
    });
  }

}








