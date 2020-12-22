import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { Router,RouterModule } from '@angular/router';
import { HttpClientModule  } from '@angular/common/http';
import { FormsModule } from '@angular/forms';
import { AppComponent } from './app.component';
import { HomeComponent } from './home/home.component';
import { AboutComponent } from './about/about.component';
import { ContactComponent } from './contact/contact.component';

import { AppRoutingModule } from './/app-routing.module';
import { NotFoundComponent } from './not-found/not-found.component';

@NgModule({
  declarations: [
    AppComponent,
    HomeComponent,
    AboutComponent,
    ContactComponent,
    NotFoundComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    FormsModule,
    RouterModule.forRoot([
      {path: "", component: HomeComponent},
      {path: "home", component: HomeComponent},
      // {path: "register", component: RegisterComponent},
      {path: "about", component: AboutComponent},
      {path: "contact", component: ContactComponent},
      {path: "**", component: NotFoundComponent}
    ])
  ],
  providers: [HttpClientModule],
  bootstrap: [AppComponent]
})
export class AppModule { }
