import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { DataService } from '../data.service';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent implements OnInit {
  
  employees;
  message;
  constructor(private service: DataService, 
    public router : Router) 
  { 
   // console.log("Home.Component.JS: Home Component Created");
  }

  ngOnInit() 
  {
    console.log("Home Component Loaded")
    let resultstate=this.service.GetData();
    resultstate.subscribe((data)=>{
      this.employees = data;
    });
     
  }

  ngOnDestroy()
  {
    console.log("Home Component Destroyed")
  }

  GoToRegister()
  {
    //console.log("Route to register");
   this.router.navigate(['register']);
  }

  Delete(empNo)
  {
    //console.log(data);
    let statusOfDelete= this.service.DeleteData(empNo);
    statusOfDelete.subscribe((result:any)=>{
      if(result.affectedRows>0)
      {
        this.router.navigate(['/home']);
      }
      else
      {
        this.message = "Something went wrong!";
      }
    });
  }
  
}









