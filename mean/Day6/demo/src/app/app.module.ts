import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { HttpClientModule  } from '@angular/common/http';
import { FormsModule } from '@angular/forms';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { HomeComponent } from './home/home.component';
import { DataService } from './data.service';
import { ContactComponent } from './contact/contact.component';
import { AboutUsComponent } from './about-us/about-us.component';
import { NoShowComponent } from './no-show/no-show.component';
import { Router, RouterModule } from '@angular/router';
import { RegisterComponent } from './register/register.component';
import { EditComponent } from './edit/edit.component';
import { LoginComponent } from './login/login.component';
import { AuthService } from './auth.service';

@NgModule({
  declarations: [
    AppComponent,
    HomeComponent,
    ContactComponent,
    AboutUsComponent,
    NoShowComponent,
    RegisterComponent,
    EditComponent,
    LoginComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    FormsModule,
    RouterModule.forRoot([
      {path: "", component: HomeComponent,canActivate:[AuthService] },
      {path: "home", component: HomeComponent,canActivate:[AuthService] },
      {path: "login", component: LoginComponent},
      {path: "edit/:No", component: EditComponent,canActivate:[AuthService] },
      {path: "register", component: RegisterComponent,canActivate:[AuthService] },
      {path: "about", component: AboutUsComponent},
      {path: "contact", component: ContactComponent},
      {path: "**", component: NoShowComponent}
    ])
  ],
  providers: [HttpClientModule, DataService],
  bootstrap: [AppComponent]
})
export class AppModule 
{
  constructor(){
    console.log("App.Module.JS: App Module Created");
  }
 }
