import { Component } from '@angular/core';
import { AuthService } from './auth.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'Demo';
  
  constructor(public service: AuthService){
    console.log("App.Component.JS: App Component Created");
  }

  Logout()
  {
    this.service.Logout();
  }
}
