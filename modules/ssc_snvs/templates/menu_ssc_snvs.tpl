<div class="row">
<div class="col-sm-9">
<div class="panel panel-primary">
    <div class="panel-heading" onclick="hideFilter(this)">
        Selection Filter
        <label class="advancedOptions" id="advanced-label" style="display:none">(Advanced Options)</label>
        <span class="glyphicon arrow glyphicon-chevron-up pull-right"></span>
    </div>
    <div class="panel-body">
        <form method="post" action="{$baseurl}/ssc_snvs/">
            <div class="row">
                <div class="form-group col-sm-4">
                    <label class="col-sm-12 col-md-4">
                        {$form.ISSID.label}
                    </label>
                    <div class="col-sm-12 col-md-8">
                        {$form.ISSID.html}
                    </div>
                </div>
                <div class="form-group col-sm-4">
                    <label class="col-sm-12 col-md-4">
                        {$form.IID.label}
                    </label>
                    <div class="col-sm-12 col-md-8">
                        {$form.IID.html}
                    </div>
                </div>                
                <div class="form-group col-sm-4">
                    <label class="col-sm-12 col-md-4">
                        {$form.FID.label}
                    </label>
                    <div class="col-sm-12 col-md-8">
                        {$form.FID.html}
                    </div>
                </div>
                <div class="form-group col-sm-4">
                    <label class="col-sm-12 col-md-4">
                        {$form.CHR.label}
                    </label>
                    <div class="col-sm-12 col-md-8">
                        {$form.CHR.html}
                    </div>
                </div>
                <div class="form-group col-sm-4">
                    <label class="col-sm-12 col-md-4">
                        {$form.START.label}
                    </label>
                    <div class="col-sm-12 col-md-8">
                        {$form.START.html}
                    </div>
                </div>
                <div class="form-group col-sm-4">
                    <label class="col-sm-12 col-md-4">
                        {$form.REF.label}
                    </label>
                    <div class="col-sm-12 col-md-8">
                        {$form.REF.html}
                    </div>
                </div>
                <div class="form-group col-sm-4">
                    <label class="col-sm-12 col-md-4">
                        {$form.ALT.label}
                    </label>
                    <div class="col-sm-12 col-md-8">
                        {$form.ALT.html}
                    </div>
                </div>
                <div class="form-group col-sm-4">
                    <label class="col-sm-12 col-md-4">
                        {$form.SNV_AnnoID.label}
                    </label>
                    <div class="col-sm-12 col-md-8">
                        {$form.SNV_AnnoID.html}
                    </div>
                </div>
            </div>
            <div class="row">                
                <div class="form-group col-sm-4"> 
                </div>     
            </div>
            <div class="advancedOptions" id="advanced-options" style="display:none">
                <div class="row">  
                </div>
                <div class="row">                    
                </div>
                <div class="row">                                       
                </div>
            </div>
            <br class="visible-xs">
            <div id="advanced-buttons">
                <!-- <div class="form-group col-sm-6 col-sm-offset-6"> -->
                        <!-- <div class="col-sm-6"> -->
                            <div class="col-sm-4 col-md-3 col-xs-12 col-md-offset-3">
                                <input type="submit" name="filter" value="Show Data" id="showdata_advanced_options" class="btn btn-sm btn-primary col-xs-12" />
                            </div>

                            <div class="visible-xs col-xs-12"> </div>
                            <div class="visible-xs col-xs-12"> </div>
                            <div class="visible-xs col-xs-12"> </div>
                            <div class="visible-xs col-xs-12"> </div>
                            <div class="col-sm-4 col-md-3 col-xs-12">
                                <input type="button" name="reset" value="Clear Form" class="btn btn-sm btn-primary col-xs-12" onclick="location.href='{$baseurl}/ssc_snvs/?reset=true'" />
                            </div>
                            <div class="visible-xs col-xs-12"> </div>
                            <div class="visible-xs col-xs-12"> </div>
                            <div class="visible-xs col-xs-12"> </div>
                            <div class="visible-xs col-xs-12"> </div>
                            <div class="col-sm-4 col-md-3 col-xs-12">
                                <input type="button" name="advanced" value="Advanced" class="btn btn-sm btn-primary col-xs-12 advanced-buttons" onclick="toggleMe()" />
                                <input type="button" name="advanced" value="Basic" class="btn btn-sm btn-primary col-xs-12 advanced-buttons" onclick="toggleMe()" style="display:none;" />
                            </div>
                        <!-- </div> -->
                    <!-- </div> -->
            </div>
        </form>
    </div>
</div>
</div>
<div id="openprofile"></div>
</div>
<div id="datatable"></div>
